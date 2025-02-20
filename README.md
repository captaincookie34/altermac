# altermac


## Commands used
- strace -f ifconfig eth0 hw ether <NEW MAC ADDR> 2> output.txt
- the above traces thee execution of the functions called such that we are able to change our MAC addresses

```bash
ioctl(4, SIOCSIFHWADDR, {ifr_name="eth0", ifr_hwaddr={sa_family=ARPHRD_ETHER, sa_data=<New-MAC>}}) = 0

Need to work with the SIOCSIFHWADDR variable
```

