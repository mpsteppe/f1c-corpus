int __thiscall UtilityFunction_03f0(_DWORD *this)
{
  int result; // eax

  switch ( ShortComputation_6720(this) )
  {
    case 0:
    case 1:
    case 2:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 1);
      VTableDispatchListIteration(this);
      result = 0;
      break;
    case 3:
    case 4:
    case 5:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 4);
      goto LABEL_4;
    default:
LABEL_4:
      VTableDispatchListIteration(this);
      result = 0;
      break;
  }
  return result;
}

