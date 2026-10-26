int __thiscall sub_46E820(int this)
{
  int *v2; // ecx
  int result; // eax
  int v4; // ecx
  int v5; // edx

  sub_4A4460();
  v2 = *(int **)(this + 340);
  if ( v2 )
    sub_459B30(v2);
  if ( dword_7656E0 && !*(_DWORD *)(this + 268) )
    *(_DWORD *)(this + 268) = sub_597290();
  *(_BYTE *)(this + 420) = 0;
  *(_BYTE *)(this + 360) = 0;
  *(_DWORD *)(this + 344) = 0;
  *(_DWORD *)(this + 348) = 0;
  *(_DWORD *)(this + 352) = 0;
  result = *(_DWORD *)(this + 276);
  v4 = *(_DWORD *)(this + 320);
  v5 = *(_DWORD *)(this + 288);
  *(_DWORD *)(this + 272) = result;
  *(_DWORD *)(this + 316) = v4;
  *(_DWORD *)(this + 292) = v5;
  return result;
}
