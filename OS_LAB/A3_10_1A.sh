# !/bin/bash

# Assignment - 1a
# Assignment Description - Familiarity with User and System level OS Commands
# Group - A3
# Team No - 10
# Roll Nos - 002311001037, 002311001042
# Names - Sougata Saha, Soham Chakraborty
# Date - 26/07/2025


# Q1. who - Print information about users who are currently logged in.
# who
# output
# (unknown) :0           2024-10-21 11:46 (:0)
# root     pts/0        2025-07-22 11:15 (172.16.5.159)
# be2304   pts/1        2025-07-22 15:47 (172.16.4.230)
# be2311   pts/3        2025-07-22 15:49 (172.16.4.231)
# be2314   pts/4        2025-07-22 16:06 (172.16.4.205)
# be2349   pts/6        2025-07-22 16:06 (172.16.4.218)
# be2382   pts/7        2025-07-22 16:06 (172.16.4.207)
# be2339   pts/8        2025-07-22 16:07 (172.16.4.216)
# be2337   pts/9        2025-07-22 16:07 (172.16.4.210)
# be2330   pts/10       2025-07-22 16:07 (172.16.4.203)
# be2392   pts/12       2025-07-22 16:08 (172.16.4.201)
# be2390   pts/13       2025-07-22 16:11 (172.16.4.212)
# be2350   pts/14       2025-07-22 16:12 (172.16.4.209)
# be2303   pts/15       2025-07-22 16:14 (172.16.4.227)
# be2342   pts/16       2025-07-22 16:19 (172.16.4.215)

# Q2. whoami - Print the user name associated with the current effective user ID.
# whoami
# output
# be2342

# Q3. pwd -  Print the full filename of the current working directory.
# pwd
# output
# /home/usr/student/ug/yr23/be2342

# Q4. date - Used to print or set the system date and time
# date
# output
# Tue Jul 22 17:21:24 IST 2025

# Q5. ls - Lists all directory contents
# ls
# output
# file1.txt  file2.txt

# Q6. mkdir - create directories if they do not already exists.
# mkdir newFile; ls
# output
# newFile

# Q7. clear - clear the terminal screen 
# clear
# output

# Q8. cd - Change the shell working directory.
# mkdir afile; pwd; cd afile; pwd
# output
# /home/soham
# /home/soham/afile

# Q9. df - report file system space usage
# df
# output
# /dev/sdd       1055762868  2163900 999895496   1% /
# rootfs            1970912     2664   1968248   1% /init
# drivers         124372988 53932664  70440324  44% /usr/lib/wsl/drivers

# Q10. rmdir - Remove the DIRECTORY(ies), if they are empty.
# mkdir afolder1; mkdir afolder2; ls; rmdir afolder1; ls
# output
# afolder1  afolder2
# afolder2

# Q11. cat - displays the content a file has
# touch file1.txt; echo "We are learning shell commands" > file1.txt; cat file1.txt
# output
# We are learning shell commands

# Q12. cp - Copy SOURCE to DEST, or multiple SOURCE(s) to DIRECTORY.
# touch file1.txt; echo "We are learning OS" > file1.txt; touch file2.txt; cp file1.txt file2.txt; cat file2.txt
# output
# We are learning OS

# Q13. mv - to move or rename files
# touch file1.txt; ls; mv file1.txt rename.txt; ls
# output
# file1.txt
# rename.txt

# Q14. rm - deletes existing file
# touch file.txt; touch file2.txt; ls; rm file.txt; ls
# output
# file.txt  file2.txt
# file2.txt

# Q15. stat - Display status of the file or folder.
# touch file.txt; stat file.txt
# output
# File: file.txt
#   Size: 0               Blocks: 0          IO Block: 4096   regular empty file
# Device: 8,48    Inode: 2215        Links: 1
# Access: (0644/-rw-r--r--)  Uid: ( 1000/   soham)   Gid: ( 1000/   soham)
# Access: 2025-07-25 15:56:06.467222781 +0000
# Modify: 2025-07-25 15:56:06.467222781 +0000
# Change: 2025-07-25 15:56:06.467222781 +0000
# Birth: 2025-07-25 15:55:45.483176247 +0000

# Q16. ln - Used to crate links between files or folders
# touch original.txt; printf "Learning ln command\n" > original.txt; ln original.txt linked.txt; cat linked.txt
# output
# Learning ln command

# Q17. tty - displays filename of terminal connected to standard input
# output
# tty
# output
# /dev/pts/0
# !/bin/bash

# Q18.  uname - print system information
# uname -a
# output
# Linux localhost.localdomain 3.10.0-514.21.1.el7.x86_64 #1 SMP Thu May 25 12:04:35 CDT 2017 x86_64 x86_64 x86_64 GNU/Linux

# Q19. umask – It specifies user file creation mask, implying which of the 3 permissions are to be denied to the owner,group and others.
# umask
# output
# 0022

# Q20.find -  The GNU find command searches directory trees based on specified expressions, evaluating them left to right, with security considerations for multi-user environments.
# touch file2.txt ; find .
# output
# .
# ./file1.txt
# ./file2.txt

# Q21. sort - Write sorted concatenation of all FILE(s) to standard output.
# printf "bob\nAlice\ncharlie\n" > file1.txt ; cat file1.txt ; sort file1.txt
# output
# bob 
# Alice 
# charlie
# Alice 
# bob 
# charlie

# Q22. ps -  it  displays information about a selection of the active processes.
# ps
# output
# PID TTY          TIME CMD
# 23927 pts/9    00:00:00 bash
# 28738 pts/9    00:00:00 ps

# Q23.chmod 777 - gives full permission to owner, group and others
# chmod 777 file1.txt ; ls -l file1.txt
# output
# -rwxrwxrwx. 1 be2337 ugyr23 20 Jul 22 17:25 file1.txt

# Q24.grep - Searches for patterns.
# echo 'Alice bob' >file1.txt;grep 'Alice' file1.txt
# output
# Alice bob

# Q25.touch - Update the access and modification times of each FILE to the current time.
# touch newfile.txt ; ls
# output
# file1.txt  file2.txt  newfile.txt

# Q26. more/less -  Commands used to view text files one screen at a time; less is an enhanced version of more with backward scrolling, search, and better terminal support.
# echo -e "This is line 1\n# This is line 2\n# This is line 3\n# This is line 4\n# This is line 5\n# This is line 6\n# This is line 7\n# This is line 8\n# This is line 9\n# This is line 10\n# This is line 1\n# This is line 2\n# This is line 3\n# This is line 4\n# This is line 5\n# This is line 6\n# This is line 1\n# This is line 2\n# This is line 3\n# This is line 4\n# This is line 5\n# This is line 6\n# This is line 7\n# This is line 8\n# This is line 9\n# This is line 10\n# This is line 1\n# This is line 2\n# This is line 3" > file1.txt; more file1.txt;
# output
# This is line 1
# This is line 2
# This is line 3
# This is line 4
# This is line 5
# This is line 6
# This is line 7
# This is line 8
# This is line 9
# This is line 10
# This is line 1
# This is line 2
# This is line 3
# This is line 4
# This is line 5
# This is line 6
# This is line 1
# This is line 2
# This is line 3
# This is line 4
# This is line 5
# This is line 6
# This is line 7
# This is line 8
# This is line 9
# This is line 10
# This is line 1
# This is line 2
# This is line 3
# --More--(87%)
# --------------
# less file1.txt
# This is line 1
# This is line 2
# This is line 3
# This is line 4
# This is line 5
# This is line 6
# This is line 7
# This is line 8
# This is line 9
# This is line 10
# This is line 1
# This is line 2
# This is line 3
# This is line 4
# This is line 5
# This is line 6
# This is line 1
# This is line 2
# This is line 3
# This is line 4
# This is line 5
# This is line 6
# This is line 7
# This is line 8
# This is line 9
# This is line 10
# This is line 1
# This is line 2
# This is line 3
# file2.txt

# Q27. head/tail - - It displays First/Last 10 lines of a File.
# echo -e "This is line 1\n# This is line 2\n# This is line 3\n# This is line 4\n# This is line 5\n# This is line 6\n# This is line 7\n# This is line 8\n# This is line 9\n# This is line 10\n# This is line 1\n# This is line 2\n# This is line 3\n# This is line 4\n# This is line 5\n# This is line 6\n# This is line 1\n# This is line 2\n# This is line 3\n# This is line 4\n# This is line 5\n# This is line 6\n# This is line 7\n# This is line 8\n# This is line 9\n# This is line 10\n# This is line 1\n# This is line 2\n# This is line 3" >file1.txt;head file1.txt;tail file1.txt
# output
# -e This is line 1
# This is line 2
# This is line 3
# This is line 4
# This is line 5
# This is line 6
# This is line 7
# This is line 8
# This is line 9
# This is line 10
# This is line 4
# This is line 5
# This is line 6
# This is line 7
# This is line 8
# This is line 9
# This is line 10
# This is line 1
# This is line 2
# This is line 3

# Q28.top -  Displays real-time information about system processes, including CPU and memory usage, sorted by resource consumption.
# top
# output
# top - 09:43:28 up  1:42,  1 user,  load average: 0.00, 0.00, 0.00
# Tasks:  24 total,   1 running,  22 sleeping,   1 stopped,   0 zombie
# %Cpu(s):  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
# MiB Mem :   3583.2 total,   3014.1 free,    368.2 used,    200.9 buff/cache
# MiB Swap:   1024.0 total,   1024.0 free,      0.0 used.   3133.6 avail Mem

#    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
#   2473 sougata+  20   0    7812   3712   3072 R   0.3   0.1   0:00.04 top
#      1 root      20   0  166996  11904   8064 S   0.0   0.3   0:01.69 systemd
#      2 root      20   0    3060   1920   1792 S   0.0   0.1   0:00.02 init-systemd(Ub
#      8 root      20   0    3076   1852   1792 S   0.0   0.1   0:00.00 init
#     62 root      19  -1   31428  11008  10240 S   0.0   0.3   0:01.03 systemd-journal
#     91 root      20   0   23096   5860   4580 S   0.0   0.2   0:00.43 systemd-udevd
#     94 systemd+  20   0   26200  12924   8320 S   0.0   0.4   0:00.36 systemd-resolve
#     95 systemd+  20   0   89364   7168   6400 S   0.0   0.2   0:00.55 systemd-timesyn
#    178 root      20   0    4308   2560   2432 S   0.0   0.1   0:00.05 cron
#    180 message+  20   0    8584   4352   3968 S   0.0   0.1   0:00.30 dbus-daemon
#    185 root      20   0   30088  18176   9728 S   0.0   0.5   0:00.10 networkd-dispat
#    186 syslog    20   0  222404   5120   4352 S   0.0   0.1   0:00.12 rsyslogd
#    189 root      20   0   15324   7424   6528 S   0.0   0.2   0:00.26 systemd-logind
#    211 root      20   0    3240   2176   2048 S   0.0   0.1   0:00.00 agetty
#    213 root      20   0    3196   2176   2048 S   0.0   0.1   0:00.00 agetty
#    215 root      20   0  107164  21120  13184 S   0.0   0.6   0:00.07 unattended-upgr
#    282 root      20   0    3064    896    896 S   0.0   0.0   0:00.00 SessionLeader
#    283 root      20   0    3080   1024   1024 S   0.0   0.0   0:02.16 Relay(284)
#    284 sougata+  20   0    6384   5248   3456 S   0.0   0.1   0:01.23 bash
#    285 root      20   0    7528   4864   3968 S   0.0   0.1   0:00.00 login
#    337 sougata+  20   0    6236   4992   3328 S   0.0   0.1   0:00.01 bash
#    727 root      20   0  293016  20096  17280 S   0.0   0.5   0:00.12 packagekitd
#    731 root      20   0  234508   7040   6400 S   0.0   0.2   0:00.02 polkitd
#   2328 sougata+  20   0   18964  10752   6528 T   0.0   0.3   0:00.04 vi

# Q29. kill - The  default signal for kill is TERM  or terminates a Process.
# ps -p 2485 ; kill 2485
# output
# PID TTY          TIME CMD
# 2017 pts/0    00:00:00 script
# Session terminated, killing shell... ...killed.
# Script done.

# Q30. history -  Displays the list of previously executed shell commands in the current terminal session.
# history
# output
# 1755  vi file1.txt
# 1756  more file1.txt
# 1757  vi file1.txt
# 1758  more file1.txt
# 1759  vi file2.txt
# 1760  more file2.txt
# 1761  vi file2.txt
# 1762  more file2.txt
# 1763  vi file2.txt
# 1764  more file2.txt
# 1765  script file1.txt
# 1766  clear
# 1767  top
# 1768  clear
# 1769  script
# 1770  script file1.txt
# 1771  man kill
# 1772  -l
# 1773  -L
# 1774  clear
# 1775  man kill
# 1776  ls
# 1777  history

# Q31. du - Displays the disk usage of files and directories.
# du -sh
# output
# 72K  

# Q32 ping -  Sends ICMP echo requests to test network connectivity with another host
# ping google.com
# output
# PING google.com (142.251.43.206) 56(84) bytes of data.
# 64 bytes from bkk03s03-in-f14.1e100.net (142.251.43.206): icmp_seq=1 ttl=117 time=33.9 ms
# 64 bytes from bkk03s03-in-f14.1e100.net (142.251.43.206): icmp_seq=2 ttl=117 time=32.5 ms
# 64 bytes from bkk03s03-in-f14.1e100.net (142.251.43.206): icmp_seq=3 ttl=117 time=32.4 ms
# 64 bytes from bkk03s03-in-f14.1e100.net (142.251.43.206): icmp_seq=4 ttl=117 time=34.7 ms

# Q33. wc - A word and line counting tool that gives you the stats behind your stories — it counts lines, words, and characters in a file.
# wc  file1.txt
# output
# 213  1957 32721 file1.txt

# Q34. >/>> - The output redirection operator that overwrites a file with the fresh result of a command.
# ls;echo 'creating new file ' > newfile.txt;ls;cat newfile.txt
# output
# creating new file

# Q35. | - The pipeline operator that connects the output of one command to the input of another.
# ls -l | grep ".txt"
# output
# -rwxrwxrwx 1 sougatasaha sougatasaha 32721 Jul 26 08:42 file1.txt
# -rwxrwxrwx 1 sougatasaha sougatasaha   847 Jul 26 08:21 file2.txt
# -rwxrwxrwx 1 sougatasaha sougatasaha    19 Jul 26 09:02 newfile.txt