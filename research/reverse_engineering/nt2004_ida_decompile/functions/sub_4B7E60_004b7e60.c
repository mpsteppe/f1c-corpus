int __thiscall sub_4B7E60(_DWORD *this)
{
  int v2; // esi
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // edi
  _DWORD *v9; // eax
  _DWORD *v10; // edi
  _DWORD *v11; // eax
  _DWORD *v12; // esi
  int v13; // ecx
  int v14; // ecx
  int result; // eax
  int v16; // [esp+10h] [ebp-4h]

  sub_4B8290(this);
  v2 = 0;
  v16 = 0;
  while ( 1 )
  {
    switch ( v2 )
    {
      case 0:
        v3 = operator new(0x4Cu);
        v4 = v3;
        if ( v3 )
        {
          *v3 = &off_5EA3C8;
          sub_506720(v3 + 1);
          v4[11] = 0;
          v4[12] = -1;
          v4[13] = 0;
          v4[14] = -1;
          sub_506BA0(v4 + 1);
          v4[17] = 1;
          v4[18] = 0;
          v2 = v16;
          *v4 = &off_5EA3B4;
          this[1] = v4;
        }
        else
        {
          this[1] = 0;
        }
        break;
      case 1:
        v5 = operator new(0x4Cu);
        v6 = v5;
        if ( v5 )
        {
          *v5 = &off_5EA3C8;
          sub_4A7EA0(v5 + 1);
          v6[17] = 1;
          v6[18] = 0;
          *v6 = &off_5EA3A0;
          this[2] = v6;
        }
        else
        {
          this[2] = 0;
        }
        goto LABEL_20;
      case 2:
        v7 = operator new(0x4Cu);
        v8 = v7;
        if ( v7 )
        {
          *v7 = &off_5EA3C8;
          sub_506720(v7 + 1);
          v8[11] = 0;
          v8[12] = -1;
          v8[13] = 0;
          v8[14] = -1;
          sub_506BA0(v8 + 1);
          v8[17] = 1;
          v8[18] = 0;
          v2 = v16;
          *v8 = &off_5EA38C;
          this[3] = v8;
        }
        else
        {
          this[3] = 0;
        }
        break;
      case 3:
        v9 = operator new(0x44u);
        v10 = v9;
        if ( v9 )
        {
          *v9 = &off_5EA3C8;
          sub_506720(v9 + 1);
          v10[11] = 0;
          v10[12] = -1;
          v10[13] = 0;
          v10[14] = -1;
          sub_506BA0(v10 + 1);
          v2 = v16;
          *v10 = &off_5EA378;
          this[4] = v10;
        }
        else
        {
          this[4] = 0;
        }
        break;
      case 4:
        v11 = operator new(0x50u);
        v12 = v11;
        if ( v11 )
        {
          *v11 = &off_5EA3C8;
          sub_4A7EA0(v11 + 1);
          v12[17] = 1;
          v12[18] = 0;
          *v12 = &off_5EA364;
        }
        else
        {
          v12 = 0;
        }
        this[5] = v12;
LABEL_20:
        v2 = v16;
        break;
      default:
        break;
    }
    v13 = this[v2 + 1];
    if ( v13 && (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 8))(v13) )
    {
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)this[v2 + 1] + 12))(this[v2 + 1]);
      v14 = this[v2 + 1];
      if ( v14 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v14 + 4))(v14, 1);
      this[v2 + 1] = 0;
    }
    result = v2 + 1;
    v16 = v2 + 1;
    if ( v2 + 1 >= 5 )
      return result;
    ++v2;
  }
}
