int __thiscall sub_52A7D0(int this, char a2)
{
  CHAR *v3; // eax
  CHAR *v4; // eax
  CHAR *v5; // eax
  int result; // eax
  int v7; // [esp+4h] [ebp-Ch] BYREF
  int v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v7 = 0;
  v8 = (int)operator new(0x100u);
  *(_BYTE *)v8 = 0;
  v3 = *(CHAR **)dword_62A068;
  v9 = 256;
  if ( !*(_DWORD *)dword_62A068 )
    v3 = &byte_629120;
  sub_578600(v3);
  v4 = (CHAR *)dword_62A0B0;
  if ( !dword_62A0B0 )
    v4 = &byte_629120;
  sub_578560(v4);
  sub_578560(aCommon);
  sub_578560(aLogomapMas);
  v5 = (CHAR *)v8;
  if ( !v8 )
    v5 = &byte_629120;
  if ( !sub_5924D0(dword_7DA988, (int)&v7, (int)v5) )
  {
    if ( a2 )
      sub_52A580((char *)this, v7);
    sub_52A690(aWcclouds, (const char *)(this + 80));
    sub_52A690(aWccloudr, (const char *)(this + 132));
    sub_592750(v7);
  }
  result = v8;
  if ( v8 )
    return sub_5BE8AE();
  return result;
}
