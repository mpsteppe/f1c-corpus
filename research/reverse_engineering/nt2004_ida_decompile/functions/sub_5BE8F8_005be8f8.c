// positive sp value has been detected, the output may be wrong!
void __usercall sub_5BE8F8(char a1@<sf>, char a2@<of>)
{
  if ( a1 == a2 )
    JUMPOUT(0x5BE798);
  JUMPOUT(0x5BE8EA);
}
