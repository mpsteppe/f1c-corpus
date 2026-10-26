// f1c  0x004dd4e0  size=102
int __thiscall sub_4DD4E0(void *this)
{
  int v1; // edi
  int v2; // ebp
  int i; // esi
  int v4; // ecx
  int v5; // eax
  int v6; // eax

  v1 = 0;
  v2 = sub_54C210(this);
  for ( i = 0; i < v2; ++i )
  {
    v4 = sub_54C230(i);
    if ( *(float *)(v4 + 244) == 0.0 )
    {
      v5 = *(_DWORD *)(v4 + 20);
      if ( (v5 & 0x2000000) != 0 )
        v6 = 2 - ((v5 & 0x40) != 0);
      else
        v6 = 4 - ((v5 & 0x40) != 0);
    }
    else
    {
      v6 = 0;
    }
    if ( v6 > v1 )
      v1 = v6;
  }
  return v1;
}
