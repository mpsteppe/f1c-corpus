int __cdecl sub_5115EE(int a1)
{
  _DWORD *v1; // eax
  int i; // eax

  v1 = (_DWORD *)(**(int (__cdecl ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 92);
  *(_DWORD *)(a1 + 400) = v1;
  *v1 = StateReset;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 4) = CommandDispatchStateMachine;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 8) = StateCounterWithDispatch;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 12) = StreamingDataReader;
  for ( i = 16; i < 80; i += 4 )
    *(_DWORD *)(i + *(_DWORD *)(a1 + 400)) = StreamingDataReader;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 16) = JPEGMarkerParsing;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 72) = AdobePSDHeaderParser;
  return StateReset((_DWORD *)a1);
}

