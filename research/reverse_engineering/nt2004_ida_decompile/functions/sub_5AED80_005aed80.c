int __thiscall sub_5AED80(_DWORD *this, char *Str, _DWORD *a3, size_t *a4)
{
  int v6; // edx
  int v7; // esi
  unsigned int v8; // eax
  int v9; // esi
  unsigned int v10; // ebx
  void *v11; // ebp
  void *v12; // ebx
  FILE *v13; // [esp-4h] [ebp-11Ch]
  size_t v14; // [esp+10h] [ebp-108h]
  size_t ElementCount; // [esp+14h] [ebp-104h]
  char Buffer[256]; // [esp+18h] [ebp-100h] BYREF

  if ( sub_5AF100(Str) )
  {
    sprintf(Buffer, "Could not locate bitmap file %s", Str);
    sub_591C60((int)this, -2, Buffer);
    return -2;
  }
  v6 = this[74];
  v7 = this[73] << 8;
  v8 = *(_DWORD *)(v7 + v6 + 8);
  v9 = v6 + v7;
  v14 = v8;
  v10 = *(_DWORD *)(v9 + 12);
  ElementCount = v10;
  v11 = operator new(v8);
  v12 = operator new(v10);
  v13 = (FILE *)this[4];
  if ( (*(_BYTE *)v9 & 0x10) != 0 )
  {
    if ( sub_5BED6F(v12, 1u, ElementCount, v13) != ElementCount || sub_5D2750(v12, ElementCount) )
      goto LABEL_6;
  }
  else if ( sub_5BED6F(v11, 1u, v14, v13) != v14 )
  {
LABEL_6:
    sub_5BE8AE();
    sub_5BE8AE();
    sprintf(Buffer, "Error loading bit map %s", (const char *)(v9 + 20));
    sub_591C60((int)this, -1, Buffer);
    return -1;
  }
  sub_5BE8AE();
  if ( a4 )
    *a4 = v14;
  if ( a3 )
    *a3 = v11;
  else
    sub_5BE8AE();
  return 0;
}
