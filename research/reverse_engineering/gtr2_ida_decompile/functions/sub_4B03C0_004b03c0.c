int __thiscall sub_4B03C0(int this)
{
  int v2; // eax
  int v3; // eax
  const char *v4; // ecx
  const char *v5; // eax
  const char *v6; // ecx
  const char *v7; // eax
  char *v8; // eax
  char *v10; // eax
  float v11; // [esp+24h] [ebp-24Ch]
  float v12; // [esp+28h] [ebp-248h]
  float v13; // [esp+2Ch] [ebp-244h]
  int v14; // [esp+30h] [ebp-240h]
  int v15; // [esp+34h] [ebp-23Ch]
  float v16; // [esp+38h] [ebp-238h]
  int v17; // [esp+3Ch] [ebp-234h]
  int v18; // [esp+40h] [ebp-230h]
  int v19; // [esp+44h] [ebp-22Ch]
  int v20; // [esp+48h] [ebp-228h]
  int v21; // [esp+4Ch] [ebp-224h]
  int v22; // [esp+50h] [ebp-220h]
  char v23[8]; // [esp+58h] [ebp-218h] BYREF
  int v24; // [esp+60h] [ebp-210h]
  char *v25; // [esp+64h] [ebp-20Ch]
  int v26; // [esp+68h] [ebp-208h]
  int v27; // [esp+6Ch] [ebp-204h]
  char v28[136]; // [esp+98h] [ebp-1D8h] BYREF
  int v29; // [esp+120h] [ebp-150h]
  float v30; // [esp+124h] [ebp-14Ch]
  int v31; // [esp+128h] [ebp-148h]
  int v32; // [esp+12Ch] [ebp-144h]
  int v33; // [esp+130h] [ebp-140h]
  int v34; // [esp+134h] [ebp-13Ch]
  int v35; // [esp+138h] [ebp-138h]
  int v36; // [esp+13Ch] [ebp-134h]
  int v37; // [esp+140h] [ebp-130h]
  float v38; // [esp+144h] [ebp-12Ch]
  float v39; // [esp+148h] [ebp-128h]
  float v40; // [esp+14Ch] [ebp-124h]
  char v41[12]; // [esp+150h] [ebp-120h] BYREF
  char v42[16]; // [esp+15Ch] [ebp-114h] BYREF
  char v43; // [esp+16Ch] [ebp-104h] BYREF

  if ( *(_BYTE *)(this + 276) )
  {
    v2 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48), 55);
    if ( v2 )
    {
      v3 = sub_4CE170(v2);
      if ( v3 )
      {
        v27 = 1;
        v26 = 256;
        v25 = &v43;
        v24 = v3;
        sub_4ABBB0();
        sub_4DF020(*(_DWORD *)(this + 48));
        switch ( CGarageOnline::UploadFile(
                   (CGarageOnline *)dword_B6CBB8,
                   (char *)(dword_B6CBB0 + 305),
                   byte_B6DCF0,
                   v42) )
        {
          case 0:
            if ( (unsigned __int8)sub_523D70(v41, v23) )
            {
              v4 = dword_B6F68C;
              if ( !dword_B6F68C )
                v4 = WindowName;
              v22 = v37;
              v21 = v36;
              v20 = v35;
              v19 = v34;
              v18 = v33;
              v17 = v32;
              v16 = v30;
              v15 = v31;
              v14 = v29;
              v13 = v40;
              v12 = v39;
              v11 = v38;
              v5 = sub_40D7B0(v4);
              CGarageOnline::UpdateTimeTrialInfo(
                (CGarageOnline *)dword_B6CBB4,
                (char *)(dword_B6CBB0 + 305),
                v5,
                v41,
                v23,
                v28,
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22);
            }
            v6 = dword_B6F68C;
            if ( !dword_B6F68C )
              v6 = WindowName;
            v7 = sub_40D7B0(v6);
            CGarageOnline::GetFileList((CGarageOnline *)dword_B6CBB8, v7);
            if ( !(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48)) )
              return 0;
            sub_4D0AC0(54);
            v8 = sub_41D840(&byte_91CC38, "Reading Folder...");
            sub_4D93B0(v8, 0, 0, 0, 0, 0, -1, -1, -1, -1);
            return off_16C98EC();
          case 0xB:
            v10 = sub_41D840(&byte_91CC38, "TimeTrial Upload Failed. File too large.");
            goto LABEL_16;
          case 0xC:
            v10 = sub_41D840(&byte_91CC38, "TimeTrial Upload Failed. Invalid Setup File.");
            goto LABEL_16;
          case 0xD:
            v10 = sub_41D840(&byte_91CC38, "TimeTrial Upload Failed. Could not read setup file.");
LABEL_16:
            sub_615860(v10);
            break;
          default:
            break;
        }
        sub_4CD6D0("JOIN FAILURE PAGE");
      }
    }
  }
  return 0;
}
