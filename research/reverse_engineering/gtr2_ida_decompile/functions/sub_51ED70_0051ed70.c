int __thiscall sub_51ED70(void *this)
{
  int v1; // edi
  int v2; // esi
  _DWORD v5[4]; // [esp+Ch] [ebp-10h] BYREF

  v1 = dword_757C10;
  v2 = 0;
  memset(v5, 0, sizeof(v5));
  dword_FB2750 = dword_BE10A8;
  byte_FB2764 = 0;
  if ( dword_757C10 > 0 )
  {
    do
      sub_51D750(*(signed int **)(*(&dword_91E088 + v2++) + 2712), (int)v5, 0);
    while ( v2 < v1 );
  }
  return sub_5EDDD0(*(_DWORD *)(*(_DWORD *)this + 768), 0);
}
