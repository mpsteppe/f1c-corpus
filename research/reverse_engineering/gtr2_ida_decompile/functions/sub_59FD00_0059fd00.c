void __thiscall sub_59FD00(int *this, float a2)
{
  double v3; // st7
  int *v4; // edi
  void *v5; // eax
  DWORD v6; // eax
  int **v7; // esi
  int *v8; // eax
  bool v9; // zf
  int v10; // edi
  double v11; // st7
  int *v12; // eax
  int v13; // ecx
  int v14; // eax
  float v15; // edx
  int v16; // esi
  int *v17; // eax
  void *v18; // edi
  float v19; // [esp+24h] [ebp-A4h]
  float v20; // [esp+28h] [ebp-A0h]
  int **v21; // [esp+2Ch] [ebp-9Ch]
  float v22; // [esp+30h] [ebp-98h] BYREF
  int *v23; // [esp+34h] [ebp-94h]
  int v24; // [esp+38h] [ebp-90h]
  int v25; // [esp+3Ch] [ebp-8Ch]
  int v26; // [esp+40h] [ebp-88h]
  int v27; // [esp+44h] [ebp-84h]
  char Buffer[128]; // [esp+48h] [ebp-80h] BYREF

  v3 = *((float *)this + 688) - a2;
  *((float *)this + 688) = v3;
  if ( v3 <= 0.0 )
  {
    this[688] = 1028443341;
    v19 = sub_5A3EA0(this);
    v4 = this + 690;
    v20 = *((float *)this + 62);
    v5 = (void *)this[694];
    v23 = this + 690;
    if ( v5 && ((v6 = WaitForSingleObject(v5, this[695])) == 0 || v6 == 128) )
    {
      v7 = (int **)(this + 690);
      v21 = (int **)(this + 690);
    }
    else
    {
      v21 = 0;
      v7 = 0;
    }
    v8 = *v7;
    v9 = *v7 == 0;
    v7[2] = *v7;
    if ( !v9 )
    {
      v10 = *v8;
      if ( *v8 )
      {
        while ( 1 )
        {
          Buffer[0] = 0;
          v11 = v19 - *(float *)(v10 + 44);
          if ( v11 <= v20 )
          {
            if ( *(_BYTE *)(v10 + 40) )
            {
              strcpy(Buffer, "Drop Flag Set");
              sub_59FB30((char *)this, v10, (int)Buffer);
              v12 = v7[2];
            }
            else
            {
              if ( v11 > v20 * 0.5 && v20 * 0.2 < v19 - *(float *)(v10 + 48) )
              {
                v13 = *(_DWORD *)(v10 + 4);
                v24 = *(_DWORD *)v10;
                v14 = *(_DWORD *)(v10 + 8);
                v25 = v13;
                v15 = *(float *)this;
                v27 = *(_DWORD *)(v10 + 12);
                v26 = v14;
                v16 = (*(int (__thiscall **)(int *))(LODWORD(v15) + 88))(this);
                sub_5A6B10(v16, 0, 11, 0, 2, -1);
                v22 = sub_5A3EA0(this);
                sub_5A6970(&v22, 4);
                sub_59D660();
                sub_5A46A0(this, v16);
                v7 = v21;
                *(float *)(v10 + 48) = v19;
              }
              v17 = v7[2];
              if ( !v17 )
                break;
              v12 = (int *)v17[1];
              v7[2] = v12;
            }
          }
          else
          {
            sprintf(
              Buffer,
              "Maint Drop - conET=(%8.4f) lastActivity=(%8.4f) dt=(%8.4f)",
              v19,
              *(float *)(v10 + 44),
              v11);
            sub_59FB30((char *)this, v10, (int)Buffer);
            v12 = v7[2];
          }
          if ( v12 )
          {
            v10 = *v12;
            if ( *v12 )
              continue;
          }
          break;
        }
      }
      v4 = v23;
    }
    v18 = (void *)v4[4];
    if ( v18 )
      ReleaseMutex(v18);
  }
}
