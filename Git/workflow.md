Git Official Web:
https://git-scm.com

# https://git-scm.com/docs/git-clone
Download repo
$ git clone <repository>

# https://git-scm.com/docs/git-status
Display added/modified/deleted etc. diff files
$ git status
...
modified:   vSphere.gemspec
...

# https://git-scm.com/docs/git-diff
$ git diff <path>
diff --git a/vSphere.gemspec b/vSphere.gemspec
index 08ac487..65fa6bf 100644
--- a/vSphere.gemspec
+++ b/vSphere.gemspec
@@ -4,8 +4,8 @@ require 'vSphere/version'
 Gem::Specification.new do |s|
    s.name = 'vagrant-vsphere'
       s.version = VagrantPlugins::VSphere::VERSION
       -  s.authors = ['Andrew Grauch', 'Ilya Bobyr']
       +  s.authors = ['Andrew Grauch', 'Ilya Bobyr', 'Xiaotian Li']
...

# https://git-scm.com/docs/git-difftool
$ git difftool
...vimdiff...
