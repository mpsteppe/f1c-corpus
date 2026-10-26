char __userpurge sub_48D590@<al>(_DWORD *a1@<ecx>, int a2@<ebx>, int a3, int a4)
{
  char result; // al
  int v5; // edi
  _DWORD *v7; // eax
  _DWORD *v8; // eax

  result = 0;
  v5 = 0;
  if ( a4 > 0 )
  {
    while ( *(_WORD *)(a3 + 2 * v5) != 203 )
    {
      if ( *(_WORD *)(a3 + 2 * v5) == 205 )
      {
        if ( *((_BYTE *)a1 + 240) )
        {
          v7 = (_DWORD *)(*(int (__thiscall **)(_DWORD *, int))(*a1 + 180))(a1, a2);
          if ( v7 )
          {
            ++*v7;
            (*(void (__thiscall **)(_DWORD *))(*a1 + 164))(a1);
            a2 = 1;
            (*(void (__thiscall **)(_DWORD *))(*a1 + 44))(a1);
LABEL_14:
            result = 1;
            goto LABEL_15;
          }
        }
        else
        {
          ++a1[56];
          ShortComputation_8970(a1);
        }
LABEL_13:
        a2 = 1;
        (*(void (__thiscall **)(_DWORD *))(*a1 + 44))(a1);
        goto LABEL_14;
      }
LABEL_15:
      if ( ++v5 >= a4 )
        return result;
    }
    if ( *((_BYTE *)a1 + 240) )
    {
      v8 = (_DWORD *)(*(int (__thiscall **)(_DWORD *, int))(*a1 + 180))(a1, a2);
      if ( v8 )
      {
        --*v8;
        (*(void (__thiscall **)(_DWORD *))(*a1 + 164))(a1);
      }
    }
    else
    {
      --a1[56];
      ShortComputation_8970(a1);
    }
    goto LABEL_13;
  }
  return result;
}

