int __thiscall sub_47C0D0(void *this)
{
  int result; // eax

  sub_419110(byte_6292D0);
  switch ( *(_DWORD *)dword_7689CC )
  {
    case 1:
    case 2:
    case 3:
    case 6:
      sub_49D430(aSelectcircuitp);
      result = -1;
      break;
    case 4:
      sub_4B9AC0(&byte_766124);
      sub_4CE0F0(4);
      sub_49D430(aChResume);
      result = -1;
      break;
    case 5:
      if ( sub_4633A0(dword_764D70) == 3 )
      {
        sub_464AF0(dword_764D70);
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, 1);
      }
      else
      {
        sub_49D430(aMpHostTrackSel);
      }
      result = -1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
