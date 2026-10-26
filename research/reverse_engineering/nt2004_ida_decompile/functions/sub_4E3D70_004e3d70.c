void __thiscall sub_4E3D70(_DWORD *this, _BYTE *a2)
{
  char *v2; // eax
  int v3; // eax
  char *v4; // eax
  int v5; // edx
  char v6; // cl

  if ( a2 )
  {
    *a2 = 0;
    v2 = (char *)this[2];
    if ( !v2 )
      v2 = &byte_629120;
    sub_4E7690(v2);
    v3 = sub_4E7760(&unk_7D6A50);
    if ( v3 )
    {
      v4 = (char *)(v3 + 182);
      v5 = a2 - v4;
      do
      {
        v6 = *v4;
        v4[v5] = *v4;
        ++v4;
      }
      while ( v6 );
    }
  }
}
