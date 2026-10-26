// positive sp value has been detected, the output may be wrong!
int __thiscall sub_4D82A7(int this)
{
  *(_DWORD *)this = &off_711880;
  sub_4D3A70((_DWORD *)this);
  if ( *(_DWORD *)(this + 224) )
    j_j__free(*(void **)(this + 224));
  if ( *(_DWORD *)(this + 212) )
    j_j__free(*(void **)(this + 212));
  if ( *(_DWORD *)(this + 200) )
    j_j__free(*(void **)(this + 200));
  if ( *(_DWORD *)(this + 192) )
    j_j__free(*(void **)(this + 192));
  if ( *(_DWORD *)(this + 184) )
    j_j__free(*(void **)(this + 184));
  if ( *(_DWORD *)(this + 176) )
    j_j__free(*(void **)(this + 176));
  if ( *(_DWORD *)(this + 168) )
    j_j__free(*(void **)(this + 168));
  if ( *(_DWORD *)(this + 160) )
    j_j__free(*(void **)(this + 160));
  sub_525140(this + 112);
  sub_4B77F0((int *)(this + 84));
  sub_409FB0((_DWORD *)(this + 68));
  sub_409FB0((_DWORD *)(this + 52));
  return ((int (__thiscall *)(int))sub_4E3C60)(this);
}
