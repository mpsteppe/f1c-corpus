void __thiscall sub_5542F0(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  int v10; // [esp-8h] [ebp-10h]

  if ( a2 != -1 && a2 != this[10] )
  {
    switch ( a2 )
    {
      case 0:
        v3 = this + 6;
        if ( this != (_DWORD *)-24 && *v3 != 2 )
        {
          *v3 = 2;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 4, 2);
        }
        v4 = this + 7;
        if ( this != (_DWORD *)-28 && *v4 != 2 )
        {
          *v4 = 2;
          v10 = 2;
          goto LABEL_33;
        }
        break;
      case 1:
        v5 = this + 6;
        if ( this != (_DWORD *)-24 && *v5 != 2 )
        {
          *v5 = 2;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 4, 2);
        }
        v6 = this + 7;
        if ( this != (_DWORD *)-28 && *v6 != 1 )
        {
          *v6 = 1;
          v10 = 1;
          goto LABEL_33;
        }
        break;
      case 2:
        v7 = this + 6;
        if ( this != (_DWORD *)-24 && *v7 != 4 )
        {
          *v7 = 4;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 4, 4);
        }
        v8 = this + 7;
        if ( this != (_DWORD *)-28 && *v8 != 2 )
        {
          *v8 = 2;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 5, 2);
        }
        v9 = this + 8;
        if ( this != (_DWORD *)-32 && *v9 != 1 )
        {
          *v9 = 1;
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 6, 1);
        }
        break;
      case 3:
        if ( sub_554260(this + 1, 4, 2) )
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 4, 2);
        if ( sub_554260(this + 1, 5, 2) )
        {
          v10 = 2;
          goto LABEL_33;
        }
        break;
      case 4:
        if ( sub_554260(this + 1, 4, 2) )
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 4, 2);
        if ( sub_554260(this + 1, 5, 3) )
        {
          v10 = 3;
LABEL_33:
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 5, v10);
        }
        break;
      default:
        break;
    }
    this[10] = a2;
  }
}
