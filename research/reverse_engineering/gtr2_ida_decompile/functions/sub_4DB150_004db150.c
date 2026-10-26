int __fastcall sub_4DB150(_DWORD *a1, int a2, int a3, _DWORD *a4)
{
  int v4; // ebx
  int v5; // esi
  int v6; // ebp
  int v7; // edi
  _DWORD *v9; // [esp+Ah] [ebp-140h]
  int v10; // [esp+1Ah] [ebp-130h]
  char v11; // [esp+1Fh] [ebp-12Bh]
  char v12; // [esp+21h] [ebp-129h]
  int v13; // [esp+22h] [ebp-128h] BYREF
  int v14[2]; // [esp+26h] [ebp-124h] BYREF
  int v15; // [esp+2Eh] [ebp-11Ch] BYREF
  int v16; // [esp+32h] [ebp-118h]
  int v17[2]; // [esp+36h] [ebp-114h] BYREF
  int v18; // [esp+3Eh] [ebp-10Ch]
  float v19; // [esp+42h] [ebp-108h]
  int v20; // [esp+46h] [ebp-104h]
  char String[125]; // [esp+4Ah] [ebp-100h] BYREF
  __int16 v22; // [esp+C7h] [ebp-83h]
  char v23; // [esp+C9h] [ebp-81h]
  int v24[32]; // [esp+CAh] [ebp-80h] BYREF

  v4 = 0;
  memset(String, 0, sizeof(String));
  v22 = 0;
  v5 = 0;
  v23 = 0;
  v6 = 0;
  v7 = a1[190] + 1;
  v14[1] = (int)a1;
  v18 = 0;
  v16 = 0;
  v19 = 0.0;
  v20 = 0;
  v17[1] = 0;
  *(float *)&v13 = 0.0;
  v14[0] = 0;
  v17[0] = 0;
  *(float *)&v15 = 0.0;
  a1[190] = v7;
  v11 = 0;
  v12 = 0;
  if ( !sub_4DAC90(a1) )
    goto LABEL_26;
  do
  {
    if ( strstr(byte_75AF70, "}") )
    {
      if ( --v16 <= 0 )
        break;
LABEL_18:
      if ( !v11 )
        continue;
      goto LABEL_19;
    }
    if ( strstr(byte_75AF70, "{") )
    {
      ++v16;
      goto LABEL_18;
    }
    if ( sub_6134B0("LOCATION", (int)&v13, (int)v14, (int)v17, (int)&v15, 0, 0, 0, 0) )
    {
      v5 = (unsigned __int64)*(float *)&v13;
      v6 = (unsigned __int64)*(float *)v14;
      v4 = (unsigned __int64)*(float *)v17;
      v18 = (unsigned __int64)*(float *)&v15;
      v11 = 1;
    }
    else
    {
      if ( !sub_6134B0("POS-W-H", (int)&v13, (int)v14, (int)v17, (int)&v15, 0, 0, 0, 0) )
      {
        if ( sub_6131C0("SURFACE", (int)v24) )
        {
          v12 = 1;
        }
        else if ( sub_6131C0("ANIMDELTA", (int)String) )
        {
          v19 = atof(String);
        }
        else if ( sub_6131C0("ANIMRULE", (int)String) )
        {
          v20 = atol(String);
        }
        else
        {
          sub_6131C0("SUBANIMFRAME", (int)String);
        }
        goto LABEL_18;
      }
      v5 = (unsigned __int64)*(float *)v14;
      v6 = (unsigned __int64)(*(float *)&v15 + *(float *)v14);
      v4 = (unsigned __int64)*(float *)&v13;
      v18 = (unsigned __int64)(*(float *)v17 + *(float *)&v13);
      v11 = 1;
    }
LABEL_19:
    if ( v12 )
    {
      v9 = a4;
      v10 = sub_4E3950(a3, v5, v6, v4, v18, v24, 0, 1);
    }
  }
  while ( sub_4DAC90(v9) );
  if ( v10 )
  {
    if ( *(float *)&v13 > 0.0 )
      *(float *)(v10 + 20) = *(float *)&v13;
    *(_DWORD *)(v10 + 24) = v14[0];
  }
LABEL_26:
  --v9[190];
  return 0;
}
