/**
HUST ACM Contest - Algorithm Practice 1
http://acm.hust.edu.cn/vjudge/contest/view.action?cid=80772#overview

Routing(*)

Description
There is a TCP/IP net of several computers. It means that:
    1. Each computer has one or more net interfaces.
    2. Each interface is identified by its IP-address and a subnet mask - these
    are two four-byte numbers with a point after each byte. A subnet mask has a
    binary representation as follows: there are k 1-bits, then - m 0-bits,
    k + m = 8 * 4 = 32 (e.g., 212.220.35.77 - is an IP-address and 
    255.255.255.128 - is a subnet mask).
    3. Two computers belong to the same subnet, if and only if
    (IP1 AND NetMask1) = (IP2 AND NetMask2), where IPi and NetMaski - are an
    IP-address and subnet mask of i-th computer, AND - is bitwise.
    4. A packet is transmitted between two computers of one subnet directly.
    5. If two computers belong to different subnets, a packet is to be
    transmitted via some other computers. The packet can pass from one subnet to
    another only on computer that has both subnets interfaces.
Your task is to find the shortest way of a packet between two given computers.

Input
The first line contains a number N - an amount of computers in the net, then go 
N sections, describing interfaces of each computer. There is a number K in the
first line of a section - that is an amount of interfaces of the computer, then
go K lines - descriptions of the interfaces, i.e. its IP-address and a subnet
mask. The last line of an input contains two integers - the numbers of the
computers that you are to find a way between them.
You may assume that 2 <= N <= 90 and K <= 5.

Output
The word “Yes” if the route exists, then in the next line the computer numbers
passed by the packet, separated with a space. The word “No” otherwise.

Sample Input & Output
================================================================================
6
2
10.0.0.1 255.0.0.0
192.168.0.1 255.255.255.0
1
10.0.0.2 255.0.0.0
3
192.168.0.2 255.255.255.0
212.220.31.1 255.255.255.0
212.220.35.1 255.255.255.0
1
212.220.31.2 255.255.255.0
2
212.220.35.2 255.255.255.0
195.38.54.65 255.255.255.224
1 
195.38.54.94 255.255.255.224
1 6
--------------------------------------------------------------------------------
Yes
1 3 5 6
================================================================================
 */

