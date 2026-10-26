char __thiscall sub_4AD890(_DWORD *this, const char *a2)
{
  const char *v2; // eax
  int v4; // esi
  _DWORD *v5; // eax
  int v7; // [esp+Ch] [ebp-204h] BYREF
  char Buffer[512]; // [esp+10h] [ebp-200h] BYREF

  v2 = (const char *)dword_62A098;
  Buffer[0] = 0;
  if ( !dword_62A098 )
    v2 = &byte_629120;
  sprintf(Buffer, "%s%s", v2, a2);
  if ( sub_4AB340((int)Buffer, &v7) )
    return 0;
  if ( operator new(0xCu) )
    v4 = sub_4B0A30(a2, v7);
  else
    v4 = 0;
  if ( v4 )
  {
    v5 = operator new(0xCu);
    if ( v5 )
    {
      *v5 = v4;
      v5[1] = 0;
      *((_BYTE *)v5 + 8) = 1;
    }
    else
    {
      v5 = 0;
    }
    if ( this[78] )
    {
      *(_DWORD *)(this[79] + 4) = v5;
    }
    else
    {
      this[78] = v5;
      this[80] = v5;
    }
    this[79] = v5;
    ++this[81];
  }
  return 1;
}
