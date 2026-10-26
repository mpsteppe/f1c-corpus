_DWORD *__thiscall sub_457A00(int this, float a2, float a3)
{
  float v4; // edx
  float v5; // eax
  bool v6; // zf
  signed int v7; // eax
  void *v8; // ecx
  bool v9; // zf
  signed int v10; // eax
  void *v11; // ecx
  bool v12; // zf
  signed int v13; // eax
  double v14; // st7
  double v15; // st6
  float v17; // [esp+4h] [ebp-14h]
  float v18; // [esp+8h] [ebp-10h]
  float v19; // [esp+Ch] [ebp-Ch] BYREF
  float v20; // [esp+10h] [ebp-8h]
  float v21; // [esp+14h] [ebp-4h]

  StateActivatedPositionSaveRestore(1);
  v4 = *(float *)(this + 148);
  v5 = *(float *)(this + 152);
  v19 = *(float *)(this + 144);
  v20 = v4;
  v21 = v5;
  v7 = UtilityFunction_6010((void *)LODWORD(v19)) & 0x80000001;
  v6 = v7 == 0;
  if ( v7 < 0 )
    v6 = (((_BYTE)v7 - 1) | 0xFFFFFFFE) == -1;
  v17 = 1.0;
  if ( !v6 )
    v17 = -1.0;
  v10 = UtilityFunction_6010(v8) & 0x80000001;
  v9 = v10 == 0;
  if ( v10 < 0 )
    v9 = (((_BYTE)v10 - 1) | 0xFFFFFFFE) == -1;
  v18 = 1.0;
  if ( !v9 )
    v18 = -1.0;
  v13 = UtilityFunction_6010(v11) & 0x80000001;
  v12 = v13 == 0;
  if ( v13 < 0 )
    v12 = (((_BYTE)v13 - 1) | 0xFFFFFFFE) == -1;
  if ( v12 )
    v14 = 1.0;
  else
    v14 = -1.0;
  v15 = a2 * a3 * 0.5;
  if ( v15 > 0.5 )
    v15 = 0.5;
  v19 = v17 * v15 * a3 + v19;
  v20 = v18 * v15 * a3 + v20;
  v21 = v15 * v14 * a3 + v21;
  return VectorCopy((_DWORD *)this, &v19);
}
