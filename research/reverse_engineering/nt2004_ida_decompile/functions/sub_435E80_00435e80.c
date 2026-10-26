int __thiscall sub_435E80(_DWORD *this, int a2)
{
  int result; // eax
  _DWORD *v4; // eax
  int v5; // eax
  _DWORD *v6; // eax
  _DWORD ArgList[7]; // [esp+4h] [ebp-31Ch] BYREF
  char Source[256]; // [esp+20h] [ebp-300h] BYREF
  char FileName[512]; // [esp+120h] [ebp-200h] BYREF

  result = sub_435A70(a2, Source, 256);
  if ( !result )
  {
    sub_57A080(ArgList);
    sub_57B040(Source, 512);
    _chmod(FileName, 384);
    if ( (unsigned __int8)sub_57A110(Source, 0, 1, 1) )
    {
      v4 = (_DWORD *)this[7];
      this[9] = v4;
      if ( v4 && *v4 )
      {
        do
        {
          sub_435970(ArgList);
          v5 = this[9];
          if ( !v5 )
            break;
          v6 = *(_DWORD **)(v5 + 4);
          this[9] = v6;
          if ( !v6 )
            break;
        }
        while ( *v6 );
      }
      sub_57A360(ArgList);
    }
    return sub_57A0A0(ArgList);
  }
  return result;
}
