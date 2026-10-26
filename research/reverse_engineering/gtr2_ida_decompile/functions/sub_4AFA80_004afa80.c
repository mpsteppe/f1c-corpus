int __thiscall sub_4AFA80(_DWORD **this)
{
  int v2; // eax
  int v3; // esi
  const char *v4; // ecx
  const char *v5; // eax
  const char *v6; // ecx
  const char *v7; // eax
  char *v8; // eax
  int result; // eax
  char *v10; // eax
  float v11; // [esp-10h] [ebp-230h]
  float v12; // [esp-Ch] [ebp-22Ch]
  float v13; // [esp-8h] [ebp-228h]
  int v14; // [esp-4h] [ebp-224h]
  int v15; // [esp+0h] [ebp-220h]
  float v16; // [esp+4h] [ebp-21Ch]
  int v17; // [esp+8h] [ebp-218h]
  int v18; // [esp+Ch] [ebp-214h]
  int v19; // [esp+10h] [ebp-210h]
  int v20; // [esp+14h] [ebp-20Ch]
  int v21; // [esp+18h] [ebp-208h]
  char *v22; // [esp+1Ch] [ebp-204h]
  int v23; // [esp+1Ch] [ebp-204h]
  int v24; // [esp+20h] [ebp-200h]
  char v25[64]; // [esp+28h] [ebp-1F8h] BYREF
  char v26[136]; // [esp+68h] [ebp-1B8h] BYREF
  int v27; // [esp+F0h] [ebp-130h]
  float v28; // [esp+F4h] [ebp-12Ch]
  int v29; // [esp+F8h] [ebp-128h]
  int v30; // [esp+FCh] [ebp-124h]
  int v31; // [esp+100h] [ebp-120h]
  int v32; // [esp+104h] [ebp-11Ch]
  int v33; // [esp+108h] [ebp-118h]
  int v34; // [esp+10Ch] [ebp-114h]
  int v35; // [esp+110h] [ebp-110h]
  float v36; // [esp+114h] [ebp-10Ch]
  float v37; // [esp+118h] [ebp-108h]
  float v38; // [esp+11Ch] [ebp-104h]
  char v39[256]; // [esp+120h] [ebp-100h] BYREF

  v2 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 55);
  v3 = 0;
  if ( !v2 )
    return v3;
  if ( !sub_4CE170(v2) )
    return v3;
  sub_4ABBB0();
  sub_4DF020(this[12]);
  if ( !CGarageOnline::Connect((CGarageOnline *)dword_B6CBB8) )
    return v3;
  if ( CGarageOnline::FileExists((CGarageOnline *)dword_B6CBB8, v39) )
  {
    switch ( CGarageOnline::CanUploadFile((CGarageOnline *)dword_B6CBB8, (char *)(dword_B6CBB0 + 305), v39) )
    {
      case 0:
        sub_4CD6D0("TIMETRIAL_SAVE_FILE_OVERWRITE_CONFIRMATION_ONLINE");
        goto LABEL_24;
      case 0xB:
LABEL_18:
        v10 = sub_41D840(&byte_91CC38, "TimeTrial Upload Failed. File too large.");
        goto LABEL_22;
      case 0xC:
        v10 = sub_41D840(&byte_91CC38, "TimeTrial Upload Failed. Invalid File.");
        goto LABEL_22;
      case 0xD:
        v10 = sub_41D840(&byte_91CC38, "TimeTrial Upload Failed. Could not read file.");
        goto LABEL_22;
      case 0xE:
        v10 = sub_41D840(&byte_91CC38, "Cannot overwrite TimeTrial. You are not the owner of this file.");
LABEL_22:
        sub_615860(v10);
LABEL_23:
        sub_4CD6D0("JOIN FAILURE PAGE");
LABEL_24:
        v3 = -1;
        break;
      default:
        return v3;
    }
    return v3;
  }
  v22 = sub_41D840(&byte_91CC38, "Uploading TimeTrial...");
  sub_4EB900(off_16C9AF8, v22);
  switch ( CGarageOnline::UploadFile((CGarageOnline *)dword_B6CBB8, (char *)(dword_B6CBB0 + 305), byte_B6DCF0, v39) )
  {
    case 0:
      if ( (unsigned __int8)sub_523D70(v39, v25) )
      {
        v4 = dword_B6F68C;
        if ( !dword_B6F68C )
          v4 = WindowName;
        v23 = v35;
        v21 = v34;
        v20 = v33;
        v19 = v32;
        v18 = v31;
        v17 = v30;
        v16 = v28;
        v15 = v29;
        v14 = v27;
        v13 = v38;
        v12 = v37;
        v11 = v36;
        v5 = sub_40D7B0(v4);
        CGarageOnline::AddTimeTrialInfo(
          (CGarageOnline *)dword_B6CBB4,
          (char *)(dword_B6CBB0 + 305),
          v5,
          v39,
          v25,
          v26,
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
          v23);
      }
      v6 = dword_B6F68C;
      if ( !dword_B6F68C )
        v6 = WindowName;
      v7 = sub_40D7B0(v6);
      CGarageOnline::GetFileList((CGarageOnline *)dword_B6CBB8, v7);
      if ( !(*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 54) )
        goto LABEL_24;
      sub_4D0AC0(v24);
      v8 = sub_41D840(&byte_91CC38, "Reading Folder...");
      sub_4D93B0(v8, 0, 0, 0, 0, 0, -1, -1, -1, -1);
      result = -1;
      break;
    case 0xB:
      goto LABEL_18;
    case 0xC:
      v10 = sub_41D840(&byte_91CC38, "TimeTrial Upload Failed. Invalid Setup File.");
      goto LABEL_22;
    case 0xD:
      v10 = sub_41D840(&byte_91CC38, "TimeTrial Upload Failed. Could not read setup file.");
      goto LABEL_22;
    default:
      goto LABEL_23;
  }
  return result;
}
