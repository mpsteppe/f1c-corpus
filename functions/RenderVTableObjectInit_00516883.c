_DWORD *__cdecl sub_516883(_DWORD *a1)
{
  int v1; // edi
  _DWORD *result; // eax
  _DWORD *v3; // ecx
  int v4; // edx

  a1[1] = 0;
  v1 = StubReturning0(a1);
  result = (_DWORD *)MallocWrapper(a1, 80);
  if ( result )
  {
    *result = MemoryAllocator;
    result[1] = MemoryAllocatorWithAlignment;
    result[2] = MemoryAllocatorWithChunking;
    result[3] = ChunkedBufferAlloc;
    result[4] = LinkedListNodeAllocAndInsert;
    result[5] = sub_51623E;
    result[6] = DirectXTextureSurfaceAllocation;
    result[7] = RingBufferWriteWithBoundsCheck;
    result[8] = OffsetValidationWithBufferUpdate;
    result[9] = sub_516772;
    result[10] = TwoIterationCleanup;
    result[11] = v1;
    v3 = result + 15;
    v4 = 2;
    do
    {
      *(v3 - 2) = 0;
      *v3-- = 0;
      --v4;
    }
    while ( v4 );
    result[16] = 0;
    result[17] = 0;
    result[18] = 80;
    a1[1] = result;
  }
  else
  {
    EmptyStub_7b96(a1);
    *(_DWORD *)(*a1 + 20) = 53;
    *(_DWORD *)(*a1 + 24) = 0;
    return (_DWORD *)(*(int (__cdecl **)(_DWORD *))*a1)(a1);
  }
  return result;
}
