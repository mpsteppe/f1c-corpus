int __thiscall sub_46CAF0(int this, int a2, signed int a3)
{
  signed int v3; // eax
  int v5; // edi
  const CHAR *v6; // eax
  const char *v8; // eax
  float v10; // [esp+28h] [ebp-148h]
  float v11; // [esp+2Ch] [ebp-144h]
  float v12; // [esp+30h] [ebp-140h]
  float v13; // [esp+34h] [ebp-13Ch]
  float v14; // [esp+38h] [ebp-138h]
  int v15; // [esp+3Ch] [ebp-134h]
  float v16; // [esp+40h] [ebp-130h]
  float v17; // [esp+44h] [ebp-12Ch]
  float v18; // [esp+48h] [ebp-128h]
  int v19; // [esp+4Ch] [ebp-124h]
  float v20; // [esp+50h] [ebp-120h]
  float v21; // [esp+54h] [ebp-11Ch]
  float v22; // [esp+58h] [ebp-118h]
  float v23; // [esp+5Ch] [ebp-114h]
  float v24; // [esp+60h] [ebp-110h]
  float v25; // [esp+64h] [ebp-10Ch]
  float v26; // [esp+68h] [ebp-108h]
  float v27; // [esp+6Ch] [ebp-104h]
  _BYTE v28[256]; // [esp+70h] [ebp-100h] BYREF

  v3 = 0;
  if ( a3 > 0 )
  {
    memset(v28, 0x20u, a3);
    v3 = a3;
  }
  v5 = *(_DWORD *)(this + 100);
  v28[v3] = 0;
  v20 = *(float *)(this + 12);
  v21 = *(float *)(this + 16);
  v22 = *(float *)(this + 20);
  v25 = *(float *)(this + 152);
  v23 = *(float *)(this + 52);
  v24 = *(float *)(this + 148);
  v26 = *(float *)(this + 156);
  v17 = *(float *)(this + 64);
  v13 = *(float *)(this + 48);
  v15 = *(_DWORD *)(this + 104);
  v19 = *(_DWORD *)(this + 108);
  v27 = *(float *)(this + 68);
  if ( *(_BYTE *)(this + 124) )
    v10 = *(float *)(this + 72) + *(float *)(this + 72);
  else
    v10 = *(float *)(this + 72);
  v12 = *(float *)(this + 76);
  v14 = *(float *)(this + 88);
  v6 = *(const CHAR **)(this + 4);
  v11 = *(float *)(this + 80);
  v16 = *(float *)(this + 84);
  v18 = *(float *)(this + 92);
  if ( !v6 )
    v6 = WindowName;
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%sTrackingCam=%s\n", v28, v6);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s{\n", v28);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Position=(%f, %f, %f)\n", v28, v20, v21, v22);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Orientation=(%f, %f, %f)\n", v28, v24, v25, v26);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Fov=(%f, %f)\n", v28, v13, v23);
  v8 = "TRUE";
  if ( !*(_BYTE *)(this + 96) )
    v8 = "FALSE";
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Clear=%s\n", v28, v8);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Color=(%d, %d, %d)\n", v28, v5, v15, v19);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  ClipPlanes=(%f, %f)\n", v28, v17, v27);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  LODMultiplier=(%f)\n", v28, v10);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Size=(%f, %f)\n", v28, v12, v11);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Center=(%f, %f)\n", v28, v16, v14);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  MipmapLODBias=(%f)\n", v28, v18);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Flags1=(%d)\n", v28, *(_DWORD *)(this + 116));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  Flags2=(%d)\n", v28, *(_DWORD *)(this + 120));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(
    a2,
    "%s  ActivationLocation=(%f, %f, %f)\n",
    v28,
    *(float *)(this + 128),
    *(float *)(this + 132),
    *(float *)(this + 136));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(
    a2,
    "%s  ActivationRadius=(%f)\n",
    v28,
    *(float *)(this + 140));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  TrackingRate=(%f)\n", v28, *(float *)(this + 168));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  MovementRate=(%f)\n", v28, *(float *)(this + 172));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s  ShakeRate=(%f)\n", v28, *(float *)(this + 264));
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(
    a2,
    "%s  ShakeMagnitude=(%f)\n",
    v28,
    *(float *)(this + 268));
  sub_46C4F0((_DWORD *)(this + 180), a2, a3 + 2);
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s}\n", v28);
  return 0;
}
