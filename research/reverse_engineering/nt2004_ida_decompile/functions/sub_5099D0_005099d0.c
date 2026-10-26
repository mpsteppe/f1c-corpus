char *__thiscall sub_5099D0(char *this)
{
  _DWORD *v2; // edi
  int v3; // ebx
  void *v4; // edx
  int v5; // edi
  int v6; // edx
  _BYTE *v7; // ecx
  int v8; // ecx
  int v9; // edx
  _DWORD *v10; // edi
  int v11; // ebx
  _DWORD *v12; // eax
  int v13; // edx

  sub_509870(this + 4);
  v2 = this + 220;
  v3 = 4;
  do
  {
    sub_509920(v2);
    sub_509870(v2 + 30);
    sub_509870(v2 + 47);
    sub_509980(v2);
    v2 += 76;
    --v3;
  }
  while ( v3 );
  sub_509920((_DWORD *)this + 359);
  sub_509870(this + 1556);
  sub_509870(this + 1624);
  v4 = this + 1692;
  v5 = 12;
  do
  {
    sub_509870(v4);
    v4 = (void *)(v6 + 68);
    --v5;
  }
  while ( v5 );
  v7 = this + 2916;
  do
  {
    sub_5099B0(v7);
    v7 = (_BYTE *)(v8 + 28);
  }
  while ( v9 != 1 );
  v10 = this + 3472;
  v11 = 15;
  do
  {
    sub_508200(v10);
    v10 += 187;
    --v11;
  }
  while ( v11 );
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  this[156] = 0;
  *((_DWORD *)this + 717) = 0;
  v12 = this + 516;
  v13 = 4;
  do
  {
    *v12 = 0;
    v12 += 76;
    --v13;
  }
  while ( v13 );
  *((_DWORD *)this + 643) = 0;
  *((_DWORD *)this + 644) = 0;
  *((_DWORD *)this + 645) = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 867) = 0;
  *((_DWORD *)this + 720) = 1065353216;
  return this;
}
