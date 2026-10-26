int __usercall sub_4A8000@<eax>(int a1@<ecx>, int a2@<ebx>)
{
  const CHAR *v2; // eax
  int v4; // eax
  int v5; // esi
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // esi
  const char *v10; // ebx
  int v11; // eax
  int v12; // esi
  const char *v13; // eax
  char *v14; // eax
  int result; // eax
  int v16; // [esp-10h] [ebp-B8h]
  int v17; // [esp-Ch] [ebp-B4h]
  int v18; // [esp-8h] [ebp-B0h]
  int v19; // [esp-4h] [ebp-ACh]
  int v20; // [esp-4h] [ebp-ACh]
  int v21; // [esp+0h] [ebp-A8h]
  int v22; // [esp+4h] [ebp-A4h]
  int v23; // [esp+8h] [ebp-A0h] BYREF
  int v24; // [esp+Ch] [ebp-9Ch] BYREF
  int v25; // [esp+14h] [ebp-94h] BYREF
  _DWORD v26[3]; // [esp+18h] [ebp-90h] BYREF
  _BYTE v27[52]; // [esp+24h] [ebp-84h] BYREF
  _BYTE v28[61]; // [esp+58h] [ebp-50h] BYREF
  __int16 v29; // [esp+95h] [ebp-13h]
  char v30; // [esp+97h] [ebp-11h]

  v2 = dword_B6F68C;
  if ( !dword_B6F68C )
    v2 = WindowName;
  sub_538940(&unk_BE1CFD, v2);
  v4 = sub_4CF8C0(a1);
  sub_630FE0(v27, v4, 63);
  v28[11] = 0;
  sub_4D0AC0(v19);
  sub_53D830(a1 + 596);
  sub_53D850(a1 + 596, WindowName);
  v23 = sub_5A6E90(a1 + 596);
  v5 = sub_616840("SceneOrder");
  v26[0] = v5;
  if ( v5 && byte_B722E4 )
  {
    HIBYTE(v22) = 1;
    v23 = sub_6165F0(v5);
  }
  else
  {
    HIBYTE(v22) = 0;
  }
  v6 = 0;
  v24 = 0;
  if ( v23 > 0 )
  {
    v17 = a2;
    do
    {
      if ( HIBYTE(v22) )
      {
        v7 = sub_616610(v6);
        v8 = sub_6165E0(v7);
        sub_538860(&unk_BE1CFD, v8, v17, v18, v20);
        v9 = dword_BE1CD8 + 396 * dword_BE1CD4;
      }
      else
      {
        v9 = sub_53A9E0(a1 + 596, v6);
      }
      v10 = (const char *)(v9 + 260);
      if ( (!sub_53A250((char *)(v9 + 260)) || *(_DWORD *)dword_B72314 != 5 || !sub_616630("NonMP")) && v9 )
      {
        sub_538860(&unk_BE1CFD, v9 + 260, v16, v17, v18);
        v24 = 0;
        v25 = 0;
        v23 = 0;
        if ( (unsigned __int8)sub_53A7E0((int)&v24, (int)&v25, (int)&v23, 0) )
          v11 = sub_4CF900(a1);
        else
          v11 = sub_4CF8C0(a1);
        v12 = v11;
        v13 = dword_B6F6A8;
        if ( !dword_B6F6A8 )
          v13 = WindowName;
        _stricmp(v10, v13);
        if ( v12 )
        {
          sub_630FE0(v26, v12, 63);
          v27[51] = 0;
        }
        memset(v28, 0, sizeof(v28));
        v29 = 0;
        v30 = 0;
        sub_53A410(&unk_BE1CFD, v28, 63);
        v14 = sub_41D840(&byte_91CC38, v10);
        sub_4D93B0(v28, 0, v26, v14, 0, 0, -1, -1, -1, -1);
        sub_4CF8C0(a1);
        v6 = v22;
      }
      v22 = ++v6;
    }
    while ( v6 < v21 );
  }
  sub_4D41C0(2, -1);
  sub_495A30();
  result = sub_4CE1B0(a1);
  *(_DWORD *)(a1 + 556) = result;
  return result;
}
