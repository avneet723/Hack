
export MACVIM_HOME="~/Downloads/MacVim-snapshot-64";
export PYTHONPATH="/usr/local/lib/python2.7/site-packages:$PYTHONPATH";
PATH=$MACVIM_HOME:$PATH;
alias go="ssh -Y avneeeet@rlogin.cs.vt.edu"
alias rl="ssh -Y avneeeet@rlogin.cs.vt.edu"
alias chunk="ssh -Y android@66.172.12.115"
alias pi="ssh pi@192.168.1.42" 
alias csrc="ssh -p 2200 csrcdev@csrc.cs.vt.edu"
alias 4414="ssh CS4414S13@bio.cs.vt.edu"
alias 4414s="ssh CS4414S13@kuprin.cbb.lan.bio.cs.vt.edu"
alias aws="ssh -i ~/Desktop/Hack/Startup-Engineering/startup-avneet.pem ubuntu@ec2-50-18-198-190.us-west-1.compute.amazonaws.com"

export PATH=/Users/avneeets/Desktop/Hack/devkit/bin/:$PATH
source ~/.local/bin/bashmarks.sh
[[ -s "$HOME/.rvm/scripts/rvm" ]] && source "$HOME/.rvm/scripts/rvm" # Load RVM into a shell session *as a function*

##
# Your previous /Users/avneeets/.bash_profile file was backed up as /Users/avneeets/.bash_profile.macports-saved_2013-04-19_at_13:51:01
##

# MacPorts Installer addition on 2013-04-19_at_13:51:01: adding an appropriate PATH variable for use with MacPorts.
export PATH=/opt/local/bin:/opt/local/sbin:$PATH
# Finished adapting your PATH environment variable for use with MacPorts.
