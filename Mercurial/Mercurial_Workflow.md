REF: 
https://our.internmc.facebook.com/intern/wiki/Mercurial-workflow/

# Mercurial Workflow

## Intro
Quick Start - simple set of steps
Cheat Sheet - a handly list of Mercurial commands, with Git equivalent
Basic Workflow - for noob
Pro Tips - for pro

### Concepts
**Distributed Version Control System**
Mercurial is a DVCS.
commits stay local until you push, entire history is avaialble locally
FB Mercurial is heavily customized through extensions that add functionality, it behaves very differently from vanilla hg

**Checkout**
A snapshot of the state of the repo at the time of a particular commit.

**Commit**
A set of saved changes.
You can have a stack of commits, which is a branch of local commits.

**Hash**
A globally unique hexadecimal id for a commit.

**Bookmark**
A pointer to a commit.

**revset**
Mercurial supports a query language for commits. Expressions in this lang are called revsets.

### Get a Repository
Use `fbclone` to clone a repo.

### Get Help
hg help - show common commands
hg help commands - show all commands
hg help <command> - show help for a specific command


## Basic Workflow

### Quick Start
1. get a local copy of the code repo.
```
fbclone [www|fbsource|configerator|...]
```
2. get your bearings
```
hg sl     - show where all your commits are in the repo
hg status - list the files you've changed since the most recent commit 
hg diff   - see the changes you've made to each file
```
3. sync changes from remote repo
```
arc pull | hg pull
```
4. make your code changes
```
hg mv <old_name> <new_name>
```
5. commit your changes 
```
hg commit - c
hg commit [dir] [path/to/file] - only commit certain files
hg amend - save new changes into your commit
hg amend -e - fix commit info
```
6. opiontally run linters and unit tests locally
```
arc lint - run linter
arc unit - run unit tests
buck test - ...
```
7. get a code review (and also run linter and unit tests in the cloud)
```
jf s -n - draft version
jf submit
```
8. address comments
```
hg sl
hg amend
jf submit
```
9. finish
```
click 'Ship It' from Diffs tool
Landing might fail if a conflicting change sneaks in. Run `arc pull`, inspect changes, and try again.
```

### See What's Going On

#### Where am I?
Run Super SmartLog to see an up-to-date view of your repo state.
It shows:
1) what commit you are on (marked by @)
2) code review status from the Diffs tool
3) where your bookmarks are
4) how they relate to remote/master
```
hg ssl
```

#### Which files have I changed (with uncommited changes)
```
hg status
```
M - modifed since last commit
A - you have told Mercurial to start tracking the file (using `hg add`)
R - you have told Mercurial to stop tracking the file (using `hg remove`) 
? - Mercurial doesn't know about this file, and hasn't been configured to ignore it
! - Mercurial is tracking this file, but it's missing - perhaps you've deleted it without telling Mercurial to stop tracking it

#### What changes have I made?
Show diff between commits
```
hg diff
```
Show diff of current commit
```
hg show
```
Show diff of another commit
```
hg show <commit_id>
```

### Stay Current
The master bookmark on the server is constantly moving forward as people land commits, so your local commits aren't
based on the latest version of the master. There are two ways you can keep your work up to date:
```
hg pull - to bring in new commits to your repo, then use `hg rebase` to move commits around
arc pull - to pull commits from the server and also rebase onto "the best available stable destination" at the same time 
           REF: https://our.internmc.facebook.com/intern/qa/3883/what-does-arc-pull-actually-do
```
NOTE: `hg pull` is like `git fetch`, not `git pull`, which combines `git fetch` and `git merge/rebase`.

```
a)
hg checkout <commit_id>
hg rebase -d master
or
b) 
hg rebase -s <commit_id> -d master
```

To combine `hg pull` and `hg rebase`, run:
```
arc pull
```
Instead of rebasing onto remote/master, arc pull rebases onto the stable bookmark (e.g. remote/stable).

Run arc pull daily, ideally at the beginning of each day, to ensure that you're building off stuff that's in cache.
When you run arc pull frequently, Benefits:
1) Buck builds of new projects run significantly faster.
2) Also, you get fewer merge conflicts, which makes rebases easier.

### Commit Some Work
Commiting your code is like using a save button on your work.
When you commit some work under Mercurial, it's local to your repository on your machine.
You can commit as often as you see fit.

#### Makeing a commit
After you do some work, you can create a new commit:
```
hg commit
```
If you don't want to commit every change you've made, you can interactively selete what changes to include by:
```
hg commit -i
```

#### Makeing changes to a commit
Like any other work you do, it's better to save as you go.
```
hg amend
```
This command picks up any changes you've made in your working directory and adds them to your current commit.

If you just need to make changes to your commit form but don't have any any new code changes to include, use:
```
hg metaedit
```

#### Using alternative commit flows
```
hg commit -m "title of my commit"
jf template # short form: jf t
hg metaedit
```

### Get Your Code Reviewed
The Diffs tool was formerly known as **Differential** and is part of **Phabricator**.

#### Submitting your changes for review with Jellyfish
```
jf submit # short form: jf s
```

### Switch Between Commits
You will often have many changes in progress and under review at once. It's easy and quick to change from one commit to another.

#### Saving your work
You can commit a new change
```
hg commit
```
Or amend an existing change
```
hg amend
```
#### Starting work on something new
```
hg checkout <commit_id>
```

#### Switching to another commit
```
hg sl
hg checkout <commit_id>
hg amend
```

#### Labeling commits
You can use bookmarks to name commis to make them easier to keep track of.
There are two types of bookmarks:
1) Local bookmarks, used to lable local commits
2) Remote bookmarks, which are pointers to important commits on the server

To check out (switch to) a bookmark, run:
```
hg checkout <bookmark_name>
```

### Respond to Review Comments
```
hg checkout <commit_id>
hg amend
hg amend -e
jf submit -nopublish
jf submit
```

### Finish Your Work

#### Land your changes with the Diffs tool
Click `Ship It` in the Diffs tool

#### Land your changes with `arc land`

### Resolving Conflicts

#### Understanding conflict markers
The default merge behavior for Mercurial at Facebook is 'editmerge', 
which pops up an editor for every conflict.

They are like:
```
<<<<
dest
====
source
>>>>
```

==== divide your version of the code from the master version.
<<<< shows the master version.
>>>> shows your version.

#### Fix conflicts in the editor
To fix the conflicts, remove the markers from the file and replace the whole block of code with the correctly merged code.

e.g.
Conflict:
```
$placeholder = fbts(
  'Browse',
<<<<<<< local
  'Search for dogs',
=======
  'Search for cats',
>>>>>>> other
  'Facebar placeholder'
);
```
Resolved:
```
$placeholder = fbts(
  'Browse',
  'Search for cats and dogs',
  'Facebar placeholder'
);
```
Save and exit.

#### Manually fixing conflicts
Some people prefer to resolve conflicts in manual resolution mode, which doesn't launch an editor automatically.
To change the default merge behavior to manual resolution mode, add the following to your ~/.hgrc file:
```
[ui]
merge = :merge
```

In manual resolution mode, run the following command to see which files have conflicts:
```
hg resolve --list
```

When you are done, mark files as resolved:
```
hg resolve --mark <file-or-directory-path>
```

After fixing and marking all the files with merge conflicts, continue the rebase:
```
hg rebase --continue
```
If you decide you want to abort the rebase instead of dealing with the conflicts right now, you can abort the rebase with:
```
hg rebase --abort
```
One of the benefits of manual resolution mode is that unlike the editmerge behavior, you can get a list of
how many files there are to fix up front. If there are too many, you might not want to event attempt to fix the merge conflicts.

#### Showing the base in merge conflicts
By default, Mercurial only shows the source and destination in merge conflicts. If you also want to see the base
(common ancestor) of the merge, you can change the default behavior of both 'editmerge' and for manual resolution mode.

To show the base of the merge for 'editmerge', add the following to your ~/.hgrc file.
```
[merge-tools]
editmerge.premerge = keep-merge3
```

To show the base of the merge for manual resolution mode, add the following to your ~/.hgrc file.
```
[ui]
merge = :merge3
```

#### Using custom merge tools
See Using a Custom Visual Merge Tool under Pro Tips:
https://our.internmc.facebook.com/intern/wiki/Mercurial-workflow/using-visual-diff-merge-tool/


### Cheatsheat
https://our.internmc.facebook.com/intern/wiki/Mercurial-workflow/cheat-sheet/



## Stacked Workflow

### Getting Started with Stacks 

#### make a diff
```
touch commit1
hg commit -m 'first commit'
```

#### make a dependent diff
```
touch commit2
hg commit -m 'second commit'
```

#### submit your stack for review
```
jf submit --stack
```

#### move up/down commit on stack
```
hg next/prev
```

#### amend your first commit
```
hg prev
hg amend --rebase # this amends your commit and rebases all of its children on top of the new version
```
alternatively, if you have some conflicts and want to resolve conflicts later on, you can use these two commands
```
hg amend
hg restack # your repo will look similar to what you had before, except that the commit hash is different
```

to submit your changes to the Diffs tool, run:
```
jf submit
```

#### amend your second commit
```
hg next
hg amend # NOTE the --rebase is not necessary because you are on top of the stack
```

Submitting your changes to the Diffs tool is the same as before:
```
jf submit
```

#### landing your commits

To ship your stack, use the `Ship Stacked` button in the Diffs tool

If you want to ship your commits seperately, unstack them and then resubmit them to the Diffs tool.


### Tools for Working with Stacks

* hg fsl and hg fssl
Use focused hg smart log to show just your current stack.

* hg prev and hg next
You can specify how many commits to move. e.g.
```
hg next 3
```

```
hg prev --bottom # move to the bottom of the stack
hg next --top    # move to the top of the stack
```

* hg-sl-up

#### moving commits arround

* hg rebase

* hg restack

#### submitting stacks of commits
* jf submit --stack

#### combining and splitting commits
* hg fold
* hg split









































