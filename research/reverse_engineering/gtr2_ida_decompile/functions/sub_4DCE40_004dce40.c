int __thiscall sub_4DCE40(int this)
{
  void *v2; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v9; // [esp+4h] [ebp-1B4h] BYREF
  int v10; // [esp+8h] [ebp-1B0h] BYREF
  int v11; // [esp+Ch] [ebp-1ACh] BYREF
  int v12; // [esp+10h] [ebp-1A8h] BYREF
  int v13; // [esp+14h] [ebp-1A4h] BYREF
  int v14; // [esp+18h] [ebp-1A0h] BYREF
  int v15; // [esp+1Ch] [ebp-19Ch] BYREF
  float v16[2]; // [esp+20h] [ebp-198h] BYREF
  int v17[32]; // [esp+28h] [ebp-190h] BYREF
  int v18; // [esp+A8h] [ebp-110h] BYREF
  char v19; // [esp+ACh] [ebp-10Ch]
  char v20[124]; // [esp+ADh] [ebp-10Bh] BYREF
  __int16 v21; // [esp+129h] [ebp-8Fh]
  char v22; // [esp+12Bh] [ebp-8Dh]
  int v23; // [esp+1B0h] [ebp-8h]
  int v24; // [esp+1B4h] [ebp-4h]

  v19 = 0;
  memset(v20, 0, sizeof(v20));
  v21 = 0;
  v22 = 0;
  v2 = operator new(0x64u);
  v17[0] = (int)v2;
  v24 = 0;
  if ( v2 )
    v3 = sub_4E0A60(v2, 0);
  else
    v3 = 0;
  v23 = -1;
  sub_4DF500(v3);
  v4 = *(_DWORD *)(this + 776);
  v5 = *(_DWORD *)(this + 760) + 1;
  *(_DWORD *)(this + 784) = v3;
  *(_DWORD *)(this + 760) = v5;
  *(_DWORD *)(v3 + 48) = v4;
  while ( sub_4DAC90((_DWORD *)this) )
  {
    if ( strstr(byte_75AF70, "}") )
      return off_16C9950();
    if ( sub_6131C0("NAME", (int)&v18) )
    {
      if ( *(_BYTE *)(this + 766) && *(_DWORD *)(this + 768) < 4u )
        sub_4DBCD0(this, (const char *)&v18);
      sub_4E2B70(v3, &v18);
      continue;
    }
    if ( sub_6131C0("ENTERTARGET", (int)v17) || sub_6131C0("ESCTARGET", (int)v17) )
      goto LABEL_23;
    if ( sub_6134B0("LOCATION", (int)&v12, (int)&v10, (int)&v9, (int)&v11, 0, 0, 0, 0) )
    {
      sub_4E2A80(
        (unsigned __int64)*(float *)&v12,
        (unsigned __int64)*(float *)&v10,
        (unsigned __int64)*(float *)&v9,
        (unsigned __int64)*(float *)&v11);
    }
    else if ( sub_6134B0("POS-W-H", (int)&v14, (int)&v13, (int)&v15, (int)v16, 0, 0, 0, 0) )
    {
      sub_4E2A80(
        (unsigned __int64)*(float *)&v13,
        (unsigned __int64)(*(float *)&v13 + v16[0]),
        (unsigned __int64)*(float *)&v14,
        (unsigned __int64)(*(float *)&v14 + *(float *)&v15));
    }
    else if ( sub_6134B0("LOCATION2", (int)&v12, (int)&v10, (int)&v9, (int)&v11, 0, 0, 0, 0) )
    {
      sub_4E2AA0(
        (unsigned __int64)*(float *)&v12,
        (unsigned __int64)*(float *)&v10,
        (unsigned __int64)*(float *)&v9,
        (unsigned __int64)*(float *)&v11);
    }
    else
    {
      if ( !sub_6131C0("SURFACE", (int)v17) )
      {
        if ( !sub_6131C0("PAGE_POINTER", (int)v17) )
        {
          if ( sub_6131C0("GIZMO", (int)&v20[123]) )
          {
            v7 = sub_4DC3C0(this, &v20[123]);
            if ( v7 )
              sub_4E0E80(*(_DWORD *)(this + 776), v7, *(_DWORD *)(this + 780));
          }
          continue;
        }
LABEL_23:
        sub_615860(v17);
        continue;
      }
      sub_4E0080(*(_DWORD *)(this + 776), v17, 1, 0, 1, 0, 0, 0, 0);
      v6 = sub_4DF040(*(_DWORD *)(this + 776), &v10);
      sub_4DF750(v3, v6);
    }
  }
  return off_16C9950();
}
