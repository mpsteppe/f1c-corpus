int __thiscall sub_5AEF20(_DWORD *this, _DWORD *a2, char *Str)
{
  int v5; // edx
  int v6; // esi
  unsigned int v7; // eax
  int v8; // esi
  unsigned int v9; // ebp
  void *v10; // ebx
  void *v11; // ebp
  FILE *v12; // [esp-4h] [ebp-11Ch]
  size_t v13; // [esp+10h] [ebp-108h]
  size_t ElementCount; // [esp+14h] [ebp-104h]
  char Buffer[256]; // [esp+18h] [ebp-100h] BYREF

  if ( sub_5AF100(Str) )
  {
    sprintf(Buffer, "Could not locate bitmap file %s", Str);
    sub_591C60((int)this, -2, Buffer);
    return -2;
  }
  if ( dword_7E8D40 )
  {
    v5 = this[74];
    v6 = this[73] << 8;
    v7 = *(_DWORD *)(v6 + v5 + 8);
    v8 = v5 + v6;
    v13 = v7;
    v9 = *(_DWORD *)(v8 + 12);
    ElementCount = v9;
    v10 = operator new(v7);
    v11 = operator new(v9);
    v12 = (FILE *)this[4];
    if ( (*(_BYTE *)v8 & 0x10) != 0 )
    {
      if ( sub_5BED6F(v11, 1u, ElementCount, v12) != ElementCount || sub_5D2750(v11, ElementCount) )
        goto LABEL_11;
    }
    else if ( sub_5BED6F(v10, 1u, v13, v12) != v13 )
    {
      goto LABEL_11;
    }
    if ( sub_5A6DF0(dword_7E6B48, (int)v10, v13, a2, 1, 0) )
    {
LABEL_11:
      sub_5BE8AE();
      sub_5BE8AE();
      sprintf(Buffer, "Error loading bit map %s", (const char *)(v8 + 20));
      sub_591C60((int)this, -1, Buffer);
      return -1;
    }
    sub_5BE8AE();
    sub_5BE8AE();
  }
  return 0;
}
