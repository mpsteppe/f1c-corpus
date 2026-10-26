// f1c  0x004b9ac0  size=192
int __thiscall sub_4B9AC0(float **this, int a2, int a3, float a4)
{
  char **v4; // edx
  float *v5; // eax
  float *v6; // edi

  v4 = (char **)this;
  if ( a4 == -9.9999997e37 )
    a4 = sub_4B8790(*this);
  v5 = sub_4B72A0(*v4, a2, a4);
  v6 = v5;
  if ( !v5 )
    return 0;
  if ( (unsigned __int8)sub_5001D0(v5 + 36) && !(unsigned __int8)sub_5001F0(v6 + 36) )
    return sub_5000C0(a4, (int)(v6 + 146), a3);
  if ( (unsigned __int8)sub_5001D0(v6 + 36) || !(unsigned __int8)sub_5001F0(v6 + 36) )
    return sub_500210(a4, a3);
  return sub_5000C0(a4, (int)(v6 + 38), a3);
}
