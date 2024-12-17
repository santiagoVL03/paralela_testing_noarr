# Recorrido Paralelo Optimizado de Estructuras de Datos en C++

### **Descripción**
Este repositorio presenta una **abstracción** para el recorrido optimizado de estructuras de datos regulares (como matrices multidimensionales) usando **C++ puro**. La solución se basa en una extensión de la biblioteca **Noarr**, permitiendo un diseño **agnóstico al recorrido** y adaptable para optimizaciones de memoria y ejecución paralela en CPU y GPU (TBB y CUDA).

---

## **Características Principales**
1. **Optimización de memoria**:
   - Ajuste del orden de recorrido para aprovechar cachés y prefetching.
   - Transformaciones como **tiling**, strip-mining y z-curves.

2. **Diseño agnóstico al recorrido**:
   - Separación entre lógica algorítmica y orden de acceso a memoria.
   - Transformaciones reutilizables y componibles.

3. **Paralelización eficiente**:
   - Compatible con **TBB** para CPU multicore.
   - Adaptación a **CUDA** para ejecución en GPU.
   - Soporte para memoria compartida y privatización en CUDA.

4. **Compatibilidad total**:
   - Implementado en **C++ estándar** usando meta-programación de templates.
   - Compilable con GCC y NVCC (para CUDA).

---

## **Ejemplos de Uso**

### **1. Definición de Matrices con Noarr**
```cpp
auto matrix = scalar<float>() ^ vector<'j'>() ^ vector<'i'>();
```
### **2. Multiplicación de Matrices**
```cpp
noarr::traverser(a, b, c).for_each([=](auto state) {
    c[state] += a[state] * b[state];
});

```

### **3. Transformación del Orden de Recorrido**
```cpp
auto blocks = noarr::strip_mine<'i', 'I', 'i'>(noarr::lit<16>) ^
              noarr::strip_mine<'k', 'K', 'k'>(noarr::lit<16>);
noarr::traverser(a, b, c).order(blocks).for_each([=](auto state) {
    c[state] += a[state] * b[state];
});
```

### **4. Ejecución Paralela con TBB**
```cpp
noarr::tbb_reduce_bag(
    noarr::traverser(in),
    [](auto state, auto &out) { out[state] = 0; },
    [](auto state, auto &out) { out[state] += 1; },
    out
);
```

### **5. Ejecución en GPU con CUDA**

```cpp
__global__ void histogram(auto traverser, auto in, auto out) {
    traverser.for_each([=](auto state) {
        atomicAdd(&out[noarr::idx<'v'>(in[state])], 1);
    });
}
```

## **Resultados**

   - Evaluación con Polybench-C y Polybench-GPU.
   - Rendimiento comparable a implementaciones manuales en C++ y CUDA.
   - Sin sobrecarga significativa al aplicar transformaciones y paralelización.

## **Participantes**

- **Santiago Vilca** - [santiagovl0308@gmail.com](mailto:santiagovl0308@gmail.com)  
- **Freddy Humpiri** - [fhumpiri@unsa.edu.pe](mailto:fhumpiri@unsa.edu.pe)  
- **Henry Yanqui** - [hyanquiv@unsa.edu.pe](mailto:hyanquiv@unsa.edu.pe)  
- **Manuel Nifla** - [mnifla@unsa.edu.pe](mailto:mnifla@unsa.edu.pe)

---

## **Referencias**
- **Artículo**: "Abstractions for C++ code optimizations in parallel high-performance applications".
