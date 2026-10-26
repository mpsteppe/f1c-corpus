int __thiscall sub_40D100(_DWORD *this)
{
  int v2; // ecx
  int result; // eax

  v2 = this[6];
  if ( v2 )
  {
    switch ( dword_7CFDC4 )
    {
      case 1:
        ViewCameraModeDispatch(v2, 1, 0, 1);
        result = GameActionStateMachine(this, 1, 0);
        break;
      case 2:
        ViewCameraModeDispatch(v2, 0, 0, 1);
        result = GameActionStateMachine(this, 0, 0);
        break;
      case 3:
        ViewCameraModeDispatch(v2, 3, 0, 1);
        result = GameActionStateMachine(this, 3, 0);
        break;
      case 4:
        ViewCameraModeDispatch(v2, 3, 0, 1);
        result = GameActionStateMachine(this, 5, 0);
        break;
      default:
        ViewCameraModeDispatch(v2, 2, 0, 1);
        result = GameActionStateMachine(this, 2, 0);
        break;
    }
  }
  return result;
}

