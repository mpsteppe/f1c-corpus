void __thiscall sub_50B020(_DWORD *this, char *String2)
{
  _DWORD *v3; // esi
  int v4; // ebx
  char String1[32]; // [esp+10h] [ebp-20h] BYREF

  this[627] = 0;
  v3 = this + 423;
  v4 = 12;
  do
  {
    if ( *v3 )
    {
      sub_59EA30(String1);
      if ( !_strcmpi(String1, String2) )
        this[627] = v3 + 16;
    }
    v3 += 17;
    --v4;
  }
  while ( v4 );
}
