int __thiscall sub_43580D(int this)
{
  int v2; // eax
  int v3; // edx
  int v4; // eax
  int v5; // edx
  _BYTE *v6; // eax
  int v7; // ecx

  *(_DWORD *)(this + 104) = 0;
  *(_DWORD *)(this + 108) = -1;
  v2 = this + 176;
  v3 = 44;
  do
  {
    *(_DWORD *)(v2 + 16) = 0;
    *(double *)v2 = 0.0;
    *(_DWORD *)(v2 + 20) = 0;
    *(_DWORD *)(v2 + 24) = 0;
    *(double *)(v2 + 8) = 0.0;
    *(_BYTE *)(v2 + 28) = 1;
    *(_BYTE *)(v2 + 29) = 0;
    *(_BYTE *)(v2 + 30) = 0;
    v2 += 64;
    --v3;
  }
  while ( v3 );
  v4 = this + 2992;
  v5 = 61;
  do
  {
    *(_DWORD *)(v4 + 16) = 0;
    *(double *)v4 = 0.0;
    *(_DWORD *)(v4 + 20) = 0;
    *(_DWORD *)(v4 + 24) = 0;
    *(double *)(v4 + 8) = 0.0;
    *(_BYTE *)(v4 + 28) = 1;
    *(_BYTE *)(v4 + 29) = 0;
    *(_BYTE *)(v4 + 30) = 0;
    v4 += 64;
    --v5;
  }
  while ( v5 );
  *(_DWORD *)(this + 6896) = 0;
  *(_DWORD *)(this + 6900) = 0;
  *(_DWORD *)(this + 6904) = 0;
  *(_DWORD *)(this + 6908) = 0;
  *(_DWORD *)(this + 6912) = 30;
  *(_DWORD *)(this + 6916) = 42;
  *(double *)(this + 6936) = 0.0;
  *(_BYTE *)(this + 6952) = 1;
  *(_BYTE *)(this + 6953) = 1;
  *(double *)(this + 6944) = 0.0;
  *(_BYTE *)(this + 6920) = 1;
  *(_BYTE *)this = 0;
  *(_BYTE *)(this + 112) = 0;
  *(_BYTE *)(this + 6921) = 0;
  *(_BYTE *)(this + 6922) = 0;
  *(_BYTE *)(this + 6923) = 0;
  *(_DWORD *)(this + 6924) = 0;
  *(_DWORD *)(this + 6928) = 0;
  sub_432C90();
  v6 = (_BYTE *)(this + 7338);
  v7 = 3;
  do
  {
    *(v6 - 384) = 0;
    *v6 = 0;
    v6 += 128;
    --v7;
  }
  while ( v7 );
  *(_DWORD *)(this + 7724) = 1056964608;
  *(_DWORD *)(this + 7728) = 1056964608;
  *(_DWORD *)(this + 7732) = 1056964608;
  *(_DWORD *)(this + 7736) = 1056964608;
  sub_4317D0((_DWORD *)this);
  return this;
}
