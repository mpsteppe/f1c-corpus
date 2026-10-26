int __cdecl sub_4ECA60(int a1, int a2, int a3)
{
  char v4[284]; // [esp+1Ch] [ebp-11Ch] BYREF

  (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 36);
  switch ( a3 )
  {
    case -2:
      strcpy(v4, sub_41D840(&byte_91CC38, "LOADING"));
      break;
    case 0:
      strcpy(v4, sub_41D840(&byte_91CC38, "OPEN PRACTICE"));
      break;
    case 1:
      strcpy(v4, sub_41D840(&byte_91CC38, "PRACTICE 1"));
      break;
    case 2:
      strcpy(v4, sub_41D840(&byte_91CC38, "PRACTICE 2"));
      break;
    case 3:
      strcpy(v4, sub_41D840(&byte_91CC38, "QUALIFYING 1"));
      break;
    case 4:
      strcpy(v4, sub_41D840(&byte_91CC38, "QUALIFYING 2"));
      break;
    case 5:
      strcpy(v4, sub_41D840(&byte_91CC38, "WARMUP"));
      break;
    case 6:
      strcpy(v4, sub_41D840(&byte_91CC38, "RACE"));
      break;
    default:
      return off_16C9760();
  }
  return off_16C9760();
}
