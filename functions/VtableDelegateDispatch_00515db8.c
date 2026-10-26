int __cdecl sub_515DB8(int a1)
{
  int result; // eax

  AudioVoiceChannelAllocation((int *)a1);
  ObjectBufferCopyWithValidation(a1);
  (**(void (__cdecl ***)(int))(a1 + 404))(a1);
  (**(void (__cdecl ***)(int))(a1 + 388))(a1);
  result = *(_DWORD *)(*(_DWORD *)(a1 + 388) + 4);
  **(_DWORD **)(a1 + 396) = result;
  return result;
}
