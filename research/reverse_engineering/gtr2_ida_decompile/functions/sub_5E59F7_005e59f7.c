// positive sp value has been detected, the output may be wrong!
int __thiscall sub_5E59F7(_DWORD *this, int **a2, char *a3, int a4)
{
  _DWORD *v5; // eax
  int *v6; // esi
  int v7; // edx
  unsigned int v8; // edx
  _DWORD *v9; // ecx

  v5 = operator new(0x330u);
  if ( v5 )
    v6 = sub_5E57E0(v5);
  else
    v6 = 0;
  sub_5E4F50(v6, a3, (int)this);
  v7 = *v6;
  if ( (a4 & 0x8000) == 0 )
  {
    v8 = v7 & 0xFFFF7FFF;
    v9 = this + 97;
  }
  else
  {
    v8 = v7 | 0x8000;
    v9 = this + 101;
  }
  *v6 = v8;
  if ( (a4 & 0x10000) != 0 )
    sub_5E5780(v9, (int)v6, 1);
  else
    sub_5FDFB0(v6, 1);
  if ( a2 )
    *a2 = v6;
  return 0;
}
