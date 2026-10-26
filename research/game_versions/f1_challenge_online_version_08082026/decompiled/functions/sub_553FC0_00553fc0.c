void __thiscall sub_553FC0(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // edi
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  int v15; // [esp-8h] [ebp-10h]

  if ( a2 != -1 && a2 != this[9] )
  {
    switch ( a2 )
    {
      case 0:
        v3 = this + 1;
        if ( this != (_DWORD *)-4 && *v3 != 1 )
        {
          *v3 = 1;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 1, 1);
        }
        goto LABEL_49;
      case 1:
        v9 = this + 1;
        if ( this != (_DWORD *)-4 && *v9 != 2 )
        {
          *v9 = 2;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 1, 2);
        }
        v10 = this + 2;
        if ( this != (_DWORD *)-8 && *v10 != 2 )
        {
          *v10 = 2;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 2, 2);
        }
        v11 = this + 3;
        if ( this != (_DWORD *)-12 && *v11 != 1 )
        {
          *v11 = 1;
          goto LABEL_47;
        }
        goto LABEL_49;
      case 2:
      case 8:
        if ( sub_554260(1, 7) )
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 1, 7);
        goto LABEL_44;
      case 4:
        v12 = this + 1;
        if ( this != (_DWORD *)-4 && *v12 != 4 )
        {
          *v12 = 4;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 1, 4);
        }
        v13 = this + 2;
        if ( this != (_DWORD *)-8 && *v13 != 2 )
        {
          *v13 = 2;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 2, 2);
        }
        v14 = this + 3;
        if ( this == (_DWORD *)-12 || *v14 == 1 )
          goto LABEL_49;
        *v14 = 1;
LABEL_47:
        v15 = 1;
        break;
      case 5:
        v4 = this + 1;
        if ( this != (_DWORD *)-4 && *v4 != 2 )
        {
          *v4 = 2;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 1, 2);
        }
        v5 = this + 2;
        if ( this != (_DWORD *)-8 && *v5 != 3 )
        {
          *v5 = 3;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 2, 3);
        }
        goto LABEL_49;
      case 6:
        v6 = this + 1;
        if ( this != (_DWORD *)-4 && *v6 != 4 )
        {
          *v6 = 4;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 1, 4);
        }
        v7 = this + 2;
        if ( this != (_DWORD *)-8 && *v7 != 2 )
        {
          *v7 = 2;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 2, 2);
        }
        v8 = this + 3;
        if ( this == (_DWORD *)-12 || *v8 == 3 )
          goto LABEL_49;
        *v8 = 3;
        v15 = 3;
        break;
      case 7:
      case 12:
        if ( sub_554260(1, 4) )
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 1, 4);
LABEL_44:
        if ( sub_554260(2, 2) )
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 2, 2);
        if ( sub_554260(3, 1) )
          goto LABEL_47;
        goto LABEL_49;
      default:
        goto LABEL_49;
    }
    (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 3, v15);
LABEL_49:
    this[9] = a2;
  }
}
