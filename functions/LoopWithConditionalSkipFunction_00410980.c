int __thiscall sub_410980(int *this, float a2)
{
  int result; // eax
  int i; // esi
  _DWORD *v5; // ecx

  MatrixClear(&dword_8AB710);
  result = *this;
  for ( i = 0; i < *this; ++i )
  {
    if ( !SceneObjectLoaderStateMachine(*(_DWORD *)(this[2] + 4 * i), a2) )
    {
      v5 = *(_DWORD **)(this[2] + 4 * i--);
      ConditionalCleanupChain(v5);
    }
    result = *this;
  }
  return result;
}
