int __thiscall sub_40CDE0(_DWORD *this, int a2, char a3)
{
  BOOL v3; // edi
  char v4; // bl
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax

  v3 = 0;
  v4 = 0;
  result = 1;
  switch ( a2 )
  {
    case 0:
    case 1:
    case 2:
      v7 = this[6];
      v8 = 2;
      this[2] = v7;
      if ( a2 )
      {
        if ( a2 == 1 )
          v8 = 1;
      }
      else
      {
        v8 = 0;
      }
      if ( a3 )
        ViewCameraModeDispatch(v7, v8, 1, 0);
      else
        ViewCameraModeDispatch(v7, v8, 1, 1);
      this[3] = a2;
      result = 0;
      break;
    case 3:
      if ( a3 )
        v3 = this[2] == this[6];
      this[2] = this[6];
      AudioSoundEffectController(0);
      ViewCameraModeDispatch(this[6], 3, v3, 0);
      if ( *(_BYTE *)(dword_7C54E0 + 13388) && !byte_7CFE88 )
      {
        AudioSoundEffectController(0);
        ViewCameraModeDispatch(this[6], 2, 0, 0);
        this[5] = 3;
        this[3] = 2;
        v4 = 1;
      }
      result = 0;
      if ( !v4 )
        this[3] = a2;
      break;
    case 4:
      if ( a3 )
        v3 = this[2] == this[6];
      this[2] = this[6];
      AudioSoundEffectController(0);
      ViewCameraModeDispatch(this[6], 4, v3, 0);
      this[3] = a2;
      result = 0;
      break;
    case 5:
      v9 = this[8];
      if ( *(int *)(v9 + 16) > 0 || *(int *)(this[7] + 16) > 0 )
      {
        if ( !sub_40D080 || (v10 = this[7]) == 0 || this[2] != v10 )
          this[2] = v9;
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)this[2] + 16))(this[2]);
      }
      AudioSoundEffectController(0);
      this[3] = a2;
      result = 0;
      break;
    case 7:
      this[2] = this[6];
      AudioSoundEffectController(0);
      ViewCameraModeDispatch(this[6], 5, 0, 0);
      this[3] = a2;
      result = 0;
      break;
    case 8:
      this[2] = this[6];
      AudioSoundEffectController(0);
      ViewCameraModeDispatch(this[6], 6, 0, 0);
      this[3] = a2;
      result = 0;
      break;
    case 9:
      this[2] = this[6];
      AudioSoundEffectController(0);
      ViewCameraModeDispatch(this[6], 7, 0, 0);
      this[3] = a2;
      result = 0;
      break;
    case 10:
      this[2] = this[6];
      AudioSoundEffectController(0);
      ViewCameraModeDispatch(this[6], 8, 0, 0);
      this[3] = a2;
      result = 0;
      break;
    default:
      return result;
  }
  return result;
}
