// f1c  0x005910a1  size=21
void __usercall __spoils<edx,ecx,st0> sub_5910A1(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-30h]
  _TBYTE v3; // [esp+Ch] [ebp-24h]

  *(double *)&v3 = a1;
  *(double *)&v2 = a2;
  sub_5908B0(v2, v3);
}
