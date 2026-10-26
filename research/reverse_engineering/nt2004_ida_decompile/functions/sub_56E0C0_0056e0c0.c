int __thiscall sub_56E0C0(int this, float a2)
{
  double v3; // st7
  __int16 v4; // fps
  bool v5; // c0
  char v6; // c2
  bool v7; // c3
  int result; // eax
  double v9; // st7
  void *v10; // eax
  int v11; // esi
  DWORD v12; // eax
  int **v13; // edi
  int *v14; // eax
  bool v15; // zf
  int v16; // esi
  __int16 v17; // fps
  double v18; // st7
  bool v19; // c0
  char v20; // c2
  bool v21; // c3
  int *v22; // eax
  __int16 v23; // fps
  double v24; // st6
  double v25; // st7
  bool v26; // c0
  char v27; // c2
  bool v28; // c3
  int *v29; // eax
  int *v30; // eax
  float v31; // [esp+28h] [ebp-A0h]
  float v32; // [esp+2Ch] [ebp-9Ch]
  int v34; // [esp+34h] [ebp-94h]
  char Buffer[132]; // [esp+38h] [ebp-90h] BYREF
  int v36; // [esp+C4h] [ebp-4h]

  v3 = *(float *)(this + 2724) - a2;
  *(float *)(this + 2724) = v3;
  v5 = v3 < 0.0;
  v6 = 0;
  v7 = v3 == 0.0;
  result = v4 & 0x4100;
  if ( (v4 & 0x4100) != 0 )
  {
    *(_DWORD *)(this + 2724) = 1028443341;
    v31 = sub_575000(this);
    v9 = *(float *)(this + 232);
    v10 = *(void **)(this + 2748);
    v11 = this + 2732;
    v34 = v11;
    v32 = v9;
    if ( v10 && ((v12 = WaitForSingleObject(v10, *(_DWORD *)(v11 + 20))) == 0 || v12 == 128) )
      v13 = (int **)v11;
    else
      v13 = 0;
    v14 = *v13;
    v15 = *v13 == 0;
    v13[2] = *v13;
    if ( !v15 )
    {
      v16 = *v14;
      if ( *v14 )
      {
        while ( 1 )
        {
          Buffer[0] = 0;
          v18 = v31 - *(float *)(v16 + 44);
          v36 = 0;
          v19 = v18 < v32;
          v20 = 0;
          v21 = v18 == v32;
          if ( (v17 & 0x4100) == 0 )
            break;
          if ( *(_BYTE *)(v16 + 40) )
          {
            strcpy(Buffer, aDropFlagSet);
            goto LABEL_13;
          }
          v24 = v18;
          v25 = v32 * 0.5;
          v26 = v24 < v25;
          v27 = 0;
          v28 = v24 == v25;
          if ( (v23 & 0x4100) == 0 && v32 * 0.2 < v31 - *(float *)(v16 + 48) )
          {
            v29 = (int *)Iostream_init::Iostream_init((Iostream_init *)v16);
            sub_56DBC0((void *)this, *v29, v29[1], v29[2], v29[3]);
            *(float *)(v16 + 48) = v31;
          }
          v30 = v13[2];
          if ( !v30 )
          {
LABEL_21:
            v16 = 0;
            goto LABEL_22;
          }
          v22 = (int *)v30[1];
          v13[2] = v22;
LABEL_19:
          if ( !v22 )
            goto LABEL_21;
          v16 = *v22;
LABEL_22:
          v36 = -1;
          if ( !v16 )
            goto LABEL_23;
        }
        sprintf(Buffer, "Maint Drop - conET=(%8.4f) lastActivity=(%8.4f) dt=(%8.4f)", v31, *(float *)(v16 + 44), v18);
LABEL_13:
        sub_56DE40((char *)this, v16, (int)Buffer);
        v22 = v13[2];
        goto LABEL_19;
      }
LABEL_23:
      v11 = v34;
    }
    result = *(_DWORD *)(v11 + 16);
    if ( result )
      return ReleaseMutex(*(HANDLE *)(v11 + 16));
  }
  return result;
}
