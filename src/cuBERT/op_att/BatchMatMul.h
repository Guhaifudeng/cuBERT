#ifndef CUBERT_BERTQK_H
#define CUBERT_BERTQK_H

#include <cstddef>

namespace cuBERT {

    /**
     * Batch MatMul between query and key.
     * Q: [N, seq_length, num_attention_heads, size_per_head]
     * K: [N, seq_length, num_attention_heads, size_per_head]
     *
     * QK = Q * K^T: [N, seq_length, num_attention_heads, seq_length]
     */
    class Att_Q_K {
    public:
        explicit Att_Q_K(void* handle,
                        size_t max_batch_size,
                        size_t seq_length, size_t num_attention_heads, size_t size_per_head,
                        float* query, float* key, float* out,
                        float alpha = 1, float beta = 0);

        virtual ~Att_Q_K();

        void compute(size_t batch_size);

    private:
        void* handle;

        size_t seq_length;
        size_t num_attention_heads;
        size_t size_per_head;

        float alpha;
        float beta;

        // cpu/gpu buffer
        const float **query_array;
        const float **key_array;
        float **out_array;
    };

    class Att_QK_V {
    public:
        explicit Att_QK_V(void* handle,
                         size_t max_batch_size,
                         size_t seq_length, size_t num_attention_heads, size_t size_per_head,
                         float* qk, float* value, float* out,
                         float alpha = 1, float beta = 0);

        virtual ~Att_QK_V();

        void compute(size_t batch_size);

    private:
        void* handle;

        size_t seq_length;
        size_t num_attention_heads;
        size_t size_per_head;

        float alpha;
        float beta;

        // cpu/gpu buffer
        const float **qk_array;
        const float **value_array;
        float **out_array;
    };
}

#endif //CUBERT_BERTQK_H