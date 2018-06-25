Ref:
http://docs.python-guide.org/en/latest/dev/virtualenvs/

## pip
Install:
"""
sudo apt-get install -y python-pip python-dev build-essential
sudo pip install --upgrade pip virtualenv virtualenvwrapper
"""

To “freeze” the current state of the environment packages.
"""
pip freeze > requirements.txt
"""
To install the same packages using the same versions:
"""
pip install -r requirements.txt
"""


## virtualenv
1. Create a virtual environment for a project:
"""
cd my_project_folder
virtualenv my_project
"""
(alternatively)
"""
virtualenv -p /usr/bin/python2.7 my_project
"""

2. To begin using the virtual environment, it needs to be activated:
"""
source my_project/bin/activate
"""

3. If you are done working in the virtual environment for the moment, you can deactivate it:
"""
deactivate
"""

4. To delete a virtual environment, just delete its folder.
"""
rm -rf my_project
"""


## virtualenvwrapper
"""
mkdir $HOME/.virtualenvs
// put following lines in .bashrc
export WORKON_HOME=$HOME/.virtualenvs
source /usr/local/bin/virtualenvwrapper.sh
"""

1. Create a virtual environment:
For python2:
"""
mkvirtualenv my_project
"""
For python3:
"""
mkvirtualenv --python=python3.5 my_project
"""
This creates the my_project folder inside ~/.virtualenvs

2. Work on a virtual environment:
"""
workon my_project
cdvirtualenv
"""

3. Deactivating is still the same:
"""
deactivate
"""

4. To delete:
"""
rmvirtualenv venv
"""

Other commands:
"""
lsvirtualenv
cdvirtualenv
lssitepackages
cdsitepackages
"""

doc from virtualenvwrapper.sh:
# Setup:
#
#  1. Create a directory to hold the virtual environments.
#     (mkdir $HOME/.virtualenvs).
#  2. Add a line like "export WORKON_HOME=$HOME/.virtualenvs"
#     to your .bashrc.
#  3. Add a line like "source /path/to/this/file/virtualenvwrapper.sh"
#     to your .bashrc.
#  4. Run: source ~/.bashrc
#  5. Run: workon
#  6. A list of environments, empty, is printed.
#  7. Run: mkvirtualenv temp
#  8. Run: workon
#  9. This time, the "temp" environment is included.
# 10. Run: workon temp
# 11. The virtual environment is activated.
