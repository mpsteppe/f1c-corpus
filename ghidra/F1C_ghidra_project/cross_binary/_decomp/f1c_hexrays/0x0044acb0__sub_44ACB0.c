// f1c  0x0044acb0  size=609
int __thiscall sub_44ACB0(void *this, int a2, char **a3)
{
  int v3; // ebx
  int result; // eax
  int v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // esi
  int v9; // eax
  int v10; // ecx
  char v11; // dl
  float *v12; // ecx
  float *v13; // eax
  int v14; // edx
  double v15; // st7
  char v16[2]; // [esp+10h] [ebp-108h] BYREF
  __int16 v17; // [esp+12h] [ebp-106h]
  int v18; // [esp+14h] [ebp-104h]
  int v19; // [esp+18h] [ebp-100h]
  int v20; // [esp+1Ch] [ebp-FCh]
  int v21; // [esp+20h] [ebp-F8h]
  int v22; // [esp+24h] [ebp-F4h]
  int v23; // [esp+28h] [ebp-F0h]
  int v24; // [esp+2Ch] [ebp-ECh]
  void *v25; // [esp+30h] [ebp-E8h]
  int v26; // [esp+34h] [ebp-E4h]
  char v27[4]; // [esp+38h] [ebp-E0h] BYREF
  char v28; // [esp+3Ch] [ebp-DCh] BYREF
  char v29[12]; // [esp+44h] [ebp-D4h] BYREF
  _BYTE v30[12]; // [esp+50h] [ebp-C8h] BYREF
  char v31[4]; // [esp+5Ch] [ebp-BCh] BYREF
  float v32; // [esp+60h] [ebp-B8h]
  int v33[3]; // [esp+68h] [ebp-B0h] BYREF
  char v34; // [esp+74h] [ebp-A4h] BYREF
  char v35[16]; // [esp+78h] [ebp-A0h] BYREF
  char v36[16]; // [esp+88h] [ebp-90h] BYREF
  char v37[64]; // [esp+98h] [ebp-80h] BYREF
  char v38[61]; // [esp+D8h] [ebp-40h] BYREF
  __int16 v39; // [esp+115h] [ebp-3h]
  char v40; // [esp+117h] [ebp-1h]

  v38[0] = byte_5EA438;
  v25 = this;
  memset(&v38[1], 0, 0x3Cu);
  v39 = 0;
  v3 = 0;
  v40 = 0;
  v18 = -1;
  v20 = 0;
  result = sub_5452F0(a2);
  v26 = result;
  v21 = 0;
  if ( result > 0 )
  {
    do
    {
      v24 = sub_545340(v3);
      v5 = 0;
      v23 = sub_54C210(v24);
      v19 = 0;
      if ( v23 > 0 )
      {
        do
        {
          v6 = sub_54C230(v5);
          if ( (*(_DWORD *)(v6 + 20) & 0x100) == 0x100 )
          {
            v7 = 0;
            v22 = sub_54E190(v6);
            if ( v22 > 0 )
            {
              do
              {
                sub_54E240(v7);
                sub_547370(v37);
                if ( !strcmp(v37, v38) )
                {
                  LOWORD(v8) = v18;
                  v9 = v20;
                }
                else
                {
                  v8 = sub_4CE860(v37);
                  v9 = sub_4CE8D0(v8);
                  v10 = 0;
                  do
                  {
                    v11 = v37[v10];
                    v38[v10++] = v11;
                  }
                  while ( v11 );
                  v18 = v8;
                  v20 = v9;
                }
                if ( v9 )
                {
                  if ( *(float *)(v9 + 8) - *(float *)(v9 + 12) * 0.0 != 0.0 )
                  {
                    v17 = v8;
                    v16[0] = -1;
                    sub_54E1A0(v7, v27, v29, v30);
                    if ( !sub_4DD9F0(v30, v31) && v32 >= 0.001 )
                    {
                      v12 = (float *)&v28;
                      v13 = (float *)&v34;
                      v14 = 3;
                      do
                      {
                        v13 += 4;
                        *(v13 - 7) = *(v12 - 1);
                        v15 = *v12;
                        v12 += 3;
                        --v14;
                        *((double *)v13 - 3) = v15;
                        *(v13 - 4) = *(v12 - 2);
                      }
                      while ( v14 );
                      sub_44AAE0(v33, (int)v35, (int)v36, (int)v16, a3);
                    }
                  }
                }
                ++v7;
              }
              while ( v7 < v22 );
              v5 = v19;
            }
          }
          v19 = ++v5;
        }
        while ( v5 < v23 );
        v3 = v21;
      }
      result = v26;
      v21 = ++v3;
    }
    while ( v3 < v26 );
  }
  return result;
}
