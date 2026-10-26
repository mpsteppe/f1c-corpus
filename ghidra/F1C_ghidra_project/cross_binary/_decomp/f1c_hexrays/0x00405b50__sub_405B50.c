// f1c  0x00405b50  size=54
int __thiscall sub_405B50(_DWORD *this)
{
  int v2; // eax
  int v3; // eax

  v2 = this[22];
  if ( v2 && ((v3 = AIL_sample_status(*(_DWORD *)(v2 + 16)), v3 == 4) || v3 == 16) )
    return this[5] != 0;
  else
    return 2;
}
