#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void solve(){
cout<<"\n----------------Subnetting is the process of dividing a larger IP network into smaller,
manageable sub-networks called subnets to improve efficiency, security, and address
management.----------\n";
int a,b,c,d;
cout<<"Enter the digits of your IP address , seperating numbers with space instead of dots\n";
cin>>a>>b>>c>>d;
cout<<"Your IP Address is:- "<<a<<"."<<b<<"."<<c<<"."<<d<<endl;
if(a==127 && b==0 && c==0 && d==0){
cout<<"This is a loopback address\n";
cout<<"An IP loopback address is a reserved IP address used for testing and
troubleshooting network configurations. It allows a device to send data to itself without involving
external networks. The most commonly used loopback address is 127.0.0.1 in IPv4, often
referred to as localhost, while in IPv6, the loopback address is ::1.\n";
return;
}
if(a>=0 && a<=127){
cout<<"Class A IP Address\n";
cout<<"Range : 0.0.0.0 - 127.255.255.255\n";
cout<<"Default Subnet Mask: 255.0.0.0 (/8)\n";
cout<<"Network Bits : 8 (The first octet identifies the network)\n";
cout<<"Host Bits : 24 (The remaining three octets identify hosts within that
network)\n";
cout<<"Number of Networks : 2^7 = 128 (126 usable in practice)\n";
cout<<"Hosts per Network : 2^24 - 2 = 16,777,214\n";
cout<<"Why subtract 2? : One address is the Network Address (all host bits = 0)\n";
cout<<" and one is the Broadcast Address (all host bits = 1).\n";
return;
}
else if(a>=128 && a<=191){
cout<<"Class B IP Address\n";
cout<<"Range : 128.0.0.0 - 191.255.255.255\n";
cout<<"Default Subnet Mask: 255.255.0.0 (/16)\n";
cout<<"Network Bits : 16 (The first two octets identify the network)\n";
cout<<"Host Bits : 16 (The last two octets identify hosts within that network)\n";
cout<<"Number of Networks : 2^14 = 16,384\n";
cout<<"Hosts per Network : 2^16 - 2 = 65,534\n";
cout<<"Why subtract 2? : One address is reserved for the Network Address\n";
cout<<" and one for the Broadcast Address.\n";
return;
}
else if(a>=192 && a<=223){
cout<<"Class C IP Address\n";
cout<<"Range : 192.0.0.0 - 223.255.255.255\n";
cout<<"Default Subnet Mask: 255.255.255.0 (/24)\n";
cout<<"Network Bits : 24 (The first three octets identify the network)\n";
cout<<"Host Bits : 8 (The last octet identifies hosts within that network)\n";
cout<<"Number of Networks : 2^21 = 2,097,152\n";
cout<<"Hosts per Network : 2^8 - 2 = 254\n";
cout<<"Why subtract 2? : One address is the Network Address\n";
cout<<" and one is the Broadcast Address.\n";
return;
}
else if(a>=224 && a<=239){
cout<<"Class D IP Address\n";
cout<<"Range : 224.0.0.0 - 239.255.255.255\n";
cout<<"Purpose : Multicast Addressing\n";
cout<<"Default Subnet Mask: Not Applicable\n";
cout<<"Network Bits : Not Applicable (Class D addresses are reserved for multicast,
not network/host division)\n";
cout<<"Host Bits : Not Applicable (No host addressing is performed in Class D)\n";
cout<<"Hosts per Network : Not Applicable\n";
cout<<"Number of Networks : Not Applicable\n";
cout<<"These addresses are used for multicast groups rather than assigning\n";
cout<<"individual devices on a network.\n";
return;
}
else if(a>=240 && a<=255){
cout<<"Class E IP Address\n";
cout<<"Range : 240.0.0.0 - 255.255.255.255\n";
cout<<"Purpose : Experimental / Research\n";
cout<<"Default Subnet Mask: Not Applicable\n";
cout<<"Network Bits : Not Applicable (Reserved for experimental use, not divided into
network and host portions)\n";
cout<<"Host Bits : Not Applicable (Not used for assigning hosts)\n";
cout<<"Hosts per Network : Not Applicable\n";
cout<<"Number of Networks : Not Applicable\n";
cout<<"These addresses are reserved for experimental purposes and are not\n";
cout<<"used for normal host addressing.\n";
return;
}
else{
cout<<"Invalid input\n";
return;
}
}
int main()
{
solve();
return 0;
}