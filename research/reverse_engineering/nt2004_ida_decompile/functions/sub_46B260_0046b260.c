void __thiscall sub_46B260(_DWORD *this)
{
  int v1; // esi
  LPVOID **v2; // edi
  char v3; // al
  _DWORD *v4; // esi
  signed int v5; // ebp
  int v6; // edi
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  _DWORD *v9; // eax
  int v10; // eax
  LRESULT v11; // eax
  LRESULT v12; // eax
  LRESULT v13; // eax
  LRESULT v14; // eax
  LRESULT v15; // eax
  int v16; // eax
  int v17; // ecx
  bool v18; // cc
  int v19; // eax
  LRESULT v20; // eax
  LRESULT v21; // [esp+10h] [ebp-264h]
  char Destination[92]; // [esp+18h] [ebp-25Ch] BYREF
  char lParam[256]; // [esp+74h] [ebp-200h] BYREF
  char v25[256]; // [esp+174h] [ebp-100h] BYREF

  v1 = *this;
  while ( v1 )
  {
    v2 = (LPVOID **)v1;
    v3 = *(_BYTE *)(v1 + 8);
    v1 = *(_DWORD *)(v1 + 4);
    if ( v3 && *v2 )
      sub_4115A0(*v2, 1);
    sub_5BE8AE(v2);
  }
  v4 = this;
  v5 = 0;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  v21 = SendDlgItemMessageA(hWnd, 1003, 0x18Bu, 0, 0);
  if ( v21 > 0 )
  {
    do
    {
      if ( SendDlgItemMessageA(hWnd, 1003, 0x189u, v5, (LPARAM)lParam) != -1 )
      {
        v6 = sub_4E8DD0(lParam);
        if ( v6 )
        {
          v7 = operator new(8u);
          v8 = v7;
          if ( v7 )
          {
            *v7 = 0;
            v7[1] = -1;
            sub_578600(v6 + 260);
            v9 = operator new(0xCu);
            if ( v9 )
            {
              *v9 = v8;
              v9[1] = 0;
              *((_BYTE *)v9 + 8) = 1;
            }
            else
            {
              v9 = 0;
            }
            if ( *this )
            {
              *(_DWORD *)(this[1] + 4) = v9;
            }
            else
            {
              *this = v9;
              this[2] = v9;
            }
            this[1] = v9;
            ++this[3];
          }
        }
      }
      ++v5;
    }
    while ( v5 < v21 );
    v4 = this;
  }
  v4[2] = *v4;
  sub_462C80(Destination);
  if ( sub_464BD0(dword_764D70, (int)Destination) )
  {
    switch ( dword_7652C4 )
    {
      case 1u:
      case 2u:
        goto LABEL_25;
      case 3u:
        v10 = 3;
        break;
      case 4u:
        v10 = 4;
        break;
      case 5u:
        if ( dword_764ED8 < dword_764F14 )
          goto LABEL_27;
        if ( dword_764ED8 >= (dword_764F10 + dword_764F0C) / 2 )
          v10 = (dword_764ED8 >= 10000) + 3;
        else
LABEL_25:
          v10 = 2;
        break;
      default:
LABEL_27:
        v10 = 1;
        break;
    }
    dword_769824 = v10;
    sub_4CF410(dword_769830);
    dword_769AF0 = dword_764ED8;
    sub_4CF410(dword_769AFC);
    byte_769A78 = 1;
    sub_466780((unsigned __int8 *)&byte_769A78, byte_769A7A, byte_769A7B);
    *(_DWORD *)dword_7689CC = 5;
    sub_4CF410(dword_7689D8);
    v11 = SendDlgItemMessageA(dword_7652C0, 1028, 0x147u, 0, 0);
    if ( (unsigned int)v11 <= 2 )
    {
      dword_7673C4 = v11;
      if ( v11 >= dword_7673CC )
      {
        if ( v11 > dword_7673D0 )
          dword_7673C4 = dword_7673D0;
      }
      else
      {
        dword_7673C4 = dword_7673CC;
      }
    }
    v12 = SendDlgItemMessageA(dword_7652C0, 1029, 0x147u, 0, 0);
    dword_769320 = v12;
    if ( v12 >= dword_769328 )
    {
      if ( v12 > dword_76932C )
        dword_769320 = dword_76932C;
    }
    else
    {
      dword_769320 = dword_769328;
    }
    v13 = SendDlgItemMessageA(dword_7652C0, 1030, 0x147u, 0, 0);
    dword_769464 = v13;
    if ( v13 >= dword_76946C )
    {
      if ( v13 > dword_769470 )
        dword_769464 = dword_769470;
    }
    else
    {
      dword_769464 = dword_76946C;
    }
    v14 = SendDlgItemMessageA(dword_7652C0, 1031, 0x147u, 0, 0);
    dword_766C20 = v14;
    if ( v14 >= dword_766C28 )
    {
      if ( v14 > dword_766C2C )
        dword_766C20 = dword_766C2C;
    }
    else
    {
      dword_766C20 = dword_766C28;
    }
    v15 = SendDlgItemMessageA(dword_7652C0, 1032, 0x147u, 0, 0);
    if ( v15 )
    {
      v16 = v15 - 1;
      if ( v16 )
      {
        if ( v16 != 1 )
          goto LABEL_59;
        v17 = dword_767514;
        dword_767508 = 3;
        if ( dword_767510 > 3 )
        {
          dword_767508 = dword_767510;
          goto LABEL_59;
        }
        v18 = dword_767514 < 3;
      }
      else
      {
        v17 = dword_767514;
        dword_767508 = 2;
        if ( dword_767510 > 2 )
        {
          dword_767508 = dword_767510;
          goto LABEL_59;
        }
        v18 = dword_767514 < 2;
      }
    }
    else
    {
      v17 = dword_767514;
      dword_767508 = 0;
      if ( dword_767510 > 0 )
      {
        dword_767508 = dword_767510;
        goto LABEL_59;
      }
      v18 = dword_767514 < 0;
    }
    if ( v18 )
      dword_767508 = v17;
LABEL_59:
    sub_4CE720(7, byte_600774);
    sub_4CE720(8, byte_600775);
    sub_4CE720(1, byte_600776);
    sub_4CE720(0, byte_600777);
    sub_4CE720(2, byte_600778);
    sub_4CE720(5, byte_7652D0);
    sub_4CE720(9, byte_600779);
    sub_4CE720(3, byte_60077A);
    sub_4CE720(4, byte_60077B);
    sub_4CE720(11, byte_60077C);
    sub_4CE720(10, byte_60077D);
    byte_769AD8 = byte_7652D1 == 0;
    if ( (unsigned __int8)(byte_7652D1 == 0) >= (unsigned __int8)byte_769ADA )
    {
      if ( (unsigned __int8)(byte_7652D1 == 0) > (unsigned __int8)byte_769ADB )
        byte_769AD8 = byte_769ADB;
    }
    else
    {
      byte_769AD8 = byte_769ADA;
    }
    v19 = SendDlgItemMessageA(hWnd, 1201, 0x400u, 0, 0) + 1;
    dword_769998 = v19;
    if ( v19 >= dword_7699A0 )
    {
      if ( v19 > dword_7699A4 )
        dword_769998 = dword_7699A4;
    }
    else
    {
      dword_769998 = dword_7699A0;
    }
    *(float *)&dword_768EAC = (double)SendDlgItemMessageA(dword_7652C0, 1198, 0x400u, 0, 0) * 0.0099999998;
    if ( *(float *)&dword_768EAC >= (double)flt_768EB4 )
    {
      if ( *(float *)&dword_768EAC > (double)flt_768EB8 )
        dword_768EAC = LODWORD(flt_768EB8);
    }
    else
    {
      *(float *)&dword_768EAC = flt_768EB4;
    }
    v20 = SendDlgItemMessageA(dword_7652C0, 1199, 0x400u, 0, 0);
    *(_DWORD *)dword_7684BC = v20;
    if ( v20 >= dword_7684C4 )
    {
      if ( v20 > dword_7684C8 )
        *(_DWORD *)dword_7684BC = dword_7684C8;
    }
    else
    {
      *(_DWORD *)dword_7684BC = dword_7684C4;
    }
    sub_462D30((int)Destination);
    v25[0] = byte_629120;
    memset(&v25[1], 0, 255);
    SendDlgItemMessageA(dword_7652C0, 1024, 0xDu, 0x100u, (LPARAM)v25);
    if ( strlen(v25) )
    {
      strncpy(Destination, v25, 0x1Fu);
    }
    else
    {
      if ( strlen(Destination) )
      {
LABEL_80:
        lParam[0] = byte_629120;
        memset(&lParam[1], 0, 255);
        SendDlgItemMessageA(dword_7652C0, 1025, 0xDu, 0x100u, (LPARAM)lParam);
        sub_465200(dword_764D70, lParam);
        sub_464150(dword_764D70, (int)Destination);
        this[105] = (this[105] != 0) + 1;
        sub_469050((int)this);
        goto LABEL_81;
      }
      strncpy(Destination, aMyServer, 0x1Fu);
    }
    Destination[31] = 0;
    goto LABEL_80;
  }
LABEL_81:
  nullsub_6(Destination);
}
