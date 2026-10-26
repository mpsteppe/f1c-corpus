void __thiscall sub_469C10(CNet *this)
{
  int v2; // eax
  int v3; // ebx
  char v4; // bl
  char v5; // al
  const char *v6; // eax
  __int64 v7; // [esp+0h] [ebp-278h]
  unsigned __int16 v8; // [esp+14h] [ebp-264h] BYREF
  _BYTE v9[4]; // [esp+18h] [ebp-260h] BYREF
  char v10[4]; // [esp+1Ch] [ebp-25Ch] BYREF
  char Buffer[8]; // [esp+20h] [ebp-258h] BYREF
  char v12[125]; // [esp+28h] [ebp-250h] BYREF
  __int16 v13; // [esp+A5h] [ebp-1D3h]
  char v14; // [esp+A7h] [ebp-1D1h]
  _BYTE v15[32]; // [esp+E8h] [ebp-190h] BYREF
  _BYTE v16[160]; // [esp+108h] [ebp-170h] BYREF
  _BYTE v17[196]; // [esp+1A8h] [ebp-D0h] BYREF
  int v18; // [esp+274h] [ebp-4h]

  v2 = *((_DWORD *)this + 1);
  switch ( v2 )
  {
    case 1:
      sub_4744E0(v12);
      v18 = 0;
      if ( (unsigned __int8)sub_4747D0(v12, &v8) )
        CNet::AddServerData(this, *((_DWORD *)this + 1), v12, 0);
      goto LABEL_16;
    case 2:
      CNet::AddServerData(this, v2, off_759E28, 0);
      return;
    case 3:
      Buffer[0] = 0;
      sprintf(Buffer, "%1.3f", 1.0);
      CNet::AddServerData(this, *((_DWORD *)this + 1), Buffer, 0);
      return;
    case 4:
      sub_4744E0(v15);
      v18 = 1;
      if ( (unsigned __int8)sub_4747D0(v15, &v8) )
        CNet::AddServerData(this, *((_DWORD *)this + 1), v8, 0);
      goto LABEL_13;
    case 5:
      sub_4744E0(v15);
      v18 = 2;
      if ( (unsigned __int8)sub_4747D0(v15, &v8) )
      {
        v3 = sub_53A220(v16);
        if ( v3 )
        {
          memset(v12, 0, sizeof(v12));
          v13 = 0;
          v14 = 0;
          if ( ((int (__thiscall *)(void *, char *, int))dword_53A310)(&unk_BE1CFD, v12, 128) )
            CNet::AddServerData(this, *((_DWORD *)this + 1), (const char *)(v3 + 260), 0);
          else
            CNet::AddServerData(this, *((_DWORD *)this + 1), &v12[4], 0);
        }
      }
LABEL_13:
      v18 = -1;
      nullsub_7(v15);
      break;
    case 8:
      sub_4744E0(v12);
      v18 = 3;
      if ( (unsigned __int8)sub_4747D0(v12, v9) )
      {
        v4 = v12[105];
        LOBYTE(v8) = v12[104];
        v5 = sub_473630(&dword_B6CBA8);
        CNet::AddServerData(this, *((_DWORD *)this + 1), v4 + (char)v8 + (v5 == 0), 0);
      }
LABEL_16:
      v18 = -1;
      nullsub_7(v12);
      break;
    case 10:
      sub_4744E0(v17);
      v18 = 4;
      if ( (unsigned __int8)sub_4747D0(v17, v10) )
      {
        v7 = v17[106] - (unsigned int)(sub_473530(0) != 0);
        CNet::AddServerData(this, *((_DWORD *)this + 1), v7, (char *)HIDWORD(v7));
      }
      v18 = -1;
      nullsub_7(v17);
      break;
    case 11:
      if ( (unsigned __int8)sub_4737F0(&dword_B6CBA8) )
        CNet::AddServerData(this, *((_DWORD *)this + 1), "openplaying", 0);
      else
        CNet::AddServerData(this, *((_DWORD *)this + 1), "closedplaying", 0);
      break;
    case 19:
      v6 = (const char *)sub_473A80(0);
      CNet::AddServerData(this, *((_DWORD *)this + 1), &v6[strlen(v6) + 1] != v6 + 1, 0);
      break;
    default:
      return;
  }
}
