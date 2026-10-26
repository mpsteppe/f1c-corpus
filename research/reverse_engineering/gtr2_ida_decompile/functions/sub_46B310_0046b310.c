int __thiscall sub_46B310(int this, int a2, signed int a3)
{
  signed int v3; // eax
  float v5; // ecx
  int v6; // edx
  int v7; // edi
  const CHAR *v8; // eax
  const char *v10; // eax
  float v12; // [esp+28h] [ebp-130h]
  float v13; // [esp+2Ch] [ebp-12Ch]
  float v14; // [esp+30h] [ebp-128h]
  float v15; // [esp+34h] [ebp-124h]
  float v16; // [esp+38h] [ebp-120h]
  int v17; // [esp+3Ch] [ebp-11Ch]
  float v18; // [esp+40h] [ebp-118h]
  float v19; // [esp+44h] [ebp-114h]
  float v20; // [esp+48h] [ebp-110h]
  float v21; // [esp+4Ch] [ebp-10Ch]
  float v22; // [esp+50h] [ebp-108h]
  int v23; // [esp+54h] [ebp-104h]
  _BYTE v24[256]; // [esp+58h] [ebp-100h] BYREF

  v3 = 0;
  if ( a3 > 0 )
  {
    memset(v24, 0x20u, a3);
    v3 = a3;
  }
  v5 = *(float *)(this + 60);
  v6 = *(_DWORD *)(this + 104);
  v7 = *(_DWORD *)(this + 100);
  v24[v3] = 0;
  v15 = *(float *)(this + 56);
  v23 = *(_DWORD *)(this + 108);
  v19 = v5;
  v17 = v6;
  v13 = *(float *)(this + 64);
  v21 = *(float *)(this + 68);
  if ( *(_BYTE *)(this + 124) )
    v12 = *(float *)(this + 72) + *(float *)(this + 72);
  else
    v12 = *(float *)(this + 72);
  v20 = *(float *)(this + 84);
  v8 = *(const CHAR **)(this + 4);
  v16 = *(float *)(this + 76);
  v14 = *(float *)(this + 80);
  v18 = *(float *)(this + 88);
  v22 = *(float *)(this + 92);
  if ( !v8 )
    v8 = WindowName;
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%sLocalCam=%s\n", v24, v8);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s{\n", v24);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Fov=(%f, %f)\n", v24, v15, v19);
  v10 = "TRUE";
  if ( !*(_BYTE *)(this + 96) )
    v10 = "FALSE";
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Clear=%s\n", v24, v10);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Color=(%d, %d, %d)\n", v24, v7, v17, v23);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  ClipPlanes=(%f, %f)\n", v24, v13, v21);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  LODMultiplier=(%f)\n", v24, v12);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Size=(%f, %f)\n", v24, v16, v14);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Center=(%f, %f)\n", v24, v20, v18);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  MipmapLODBias=(%f)\n", v24, v22);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Flags1=(%d)\n", v24, *(_DWORD *)(this + 116));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Flags2=(%d)\n", v24, *(_DWORD *)(this + 120));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(
    a2,
    "%s  RadiusLimits=(%f, %f)\n",
    v24,
    *(float *)(this + 132),
    *(float *)(this + 136));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(
    a2,
    "%s  OrientationRate=(%f, %f, %f)\n",
    v24,
    *(float *)(this + 140),
    *(float *)(this + 144),
    *(float *)(this + 148));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(
    a2,
    "%s  PositionOffset=(%f, %f, %f)\n",
    v24,
    *(float *)(this + 152),
    *(float *)(this + 156),
    *(float *)(this + 160));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(
    a2,
    "%s  OrientationOffset=(%f, %f, %f)\n",
    v24,
    *(float *)(this + 164),
    *(float *)(this + 168),
    *(float *)(this + 172));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Radius=(%f)\n", v24, *(float *)(this + 176));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s}\n", v24);
  return 0;
}
