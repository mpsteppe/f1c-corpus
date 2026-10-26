// positive sp value has been detected, the output may be wrong!
void __usercall sub_429FC2(char a1@<al>)
{
  MEMORY[0xCE8B0875] += a1;
  JUMPOUT(0x42A206);
}

