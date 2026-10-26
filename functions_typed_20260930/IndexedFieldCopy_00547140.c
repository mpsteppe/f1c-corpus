int __thiscall sub_547140(void *this, int a2, int a3)
{
  int result; // eax

  result = (int)this;
  switch ( a2 )
  {
    case 1:
      result = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)dword_8B8F24 + 16))(dword_8B8F24, a3, (int)this + 84);
      break;
    case 2:
      result = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)dword_8B8F24 + 16))(dword_8B8F24, a3, (int)this + 68);
      break;
    case 3:
      result = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)dword_8B8F24 + 16))(dword_8B8F24, a3, (int)this + 100);
      break;
    case 4:
      result = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)dword_8B8F24 + 16))(dword_8B8F24, a3, (int)this + 116);
      break;
    default:
      return result;
  }
  return result;
}

