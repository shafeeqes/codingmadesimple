"""
Given a string IP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" 
if IP is not a correct IP of any type.

A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain 
leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses but "192.168.01.1", while 
"192.168.1.00" and "192.168@1.1" are invalid IPv4 addresses.

A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

1 <= xi.length <= 4
xi is a hexadecimal string which may contain digits, lower-case English letter ('a' to 'f') and upper-case 
English letters ('A' to 'F').
Leading zeros are allowed in xi.
For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 
addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.
"""


class Solution:
    def validIPAddress(self, IP: str) -> str:
        s = IP.split('.')
        IPv4 = True
        if len(s) == 1 :
            s = IP.split(':')
            IPv4 = False
        if len(s) < 0:
            return "Neither" 
        if IPv4:
            if len(s) != 4:
                return "Neither"
            for string in s:
                if not string.isdigit():
                    return "Neither"
                elif int(string) > 255 or int(string) < 0:
                    return "Neither"
                elif string[0] =='0' and len(string)!= 1:
                    return "Neither"
            
            return "IPv4"    
        
        else:
            charlist = ['a','A','b','B','c','C','d','D','e','E','f','F','0','1','2','3','4','5','6','7','8','9']
            charset = set(charlist)
            if len(s) != 8 :
                return "Neither"
            for string in s:
                if len(string) > 4 or len(string) < 1:
                    return "Neither"
                for c in string:
                    if c not in charset:
                        return "Neither"
            
            return "IPv6"        
            
