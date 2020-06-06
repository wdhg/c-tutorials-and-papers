#include "layer.h"

/* The sigmoid function and derivative. */
double sigmoid(double x) {
  /**** PART 1 - QUESTION 1 ****/
  return 1 / (1 + exp(-x));
  /* 1 MARK */
}

double sigmoidprime(double x) { return x * (1 - x); }

/* Creates a single layer. */
layer_t *layer_create() {
  /**** PART 1 - QUESTION 2 ****/
  return (layer_t *)calloc(1, sizeof(layer_t));
  /* 2 MARKS */
}

/* Initialises the given layer. */
bool layer_init(layer_t *layer, int num_outputs, layer_t *prev) {
  /**** PART 1 - QUESTION 3 ****/
  layer->num_outputs = num_outputs;
  // allocate memory for weights, biases, deltas
  layer->weights =
      calloc(layer->num_inputs * layer->num_outputs, sizeof(double));
  layer->biases = calloc(layer->num_outputs, sizeof(double));
  layer->deltas = calloc(layer->num_outputs, sizeof(double));
  if (layer->weights == NULL || layer->biases == NULL ||
      layer->deltas == NULL) {
    return true; // return true for failure
  }
  if (prev != NULL) { // check if output layer
    layer->prev = prev;
    prev->next = layer;
    layer->num_inputs = prev->num_outputs;
    // assign incoming weights, biases, deltas
    for (int output = 0; output < layer->num_outputs; output++) {
      for (int input = 0; input < layer->num_inputs; input++) {
        layer->weights[output][input] = ANN_RANDOM();
      }
    }
  }
  return false;
  /* 4 MARKS */
}

/* Frees a given layer. */
void layer_free(layer_t *layer) {
  /**** PART 1 - QUESTION 4 ****/
  if (layer == NULL) {
    return;
  }
  if (layer->weights != NULL) {
    free(layer->weights);
  }
  if (layer->biases != NULL) {
    free(layer->biases);
  }
  if (layer->deltas != NULL) {
    free(layer->deltas);
  }
  free(layer);
  /* 2 MARKS */
}

/* Computes the outputs of the current layer. */
void layer_compute_outputs(layer_t const *layer) {
  /**** PART 1 - QUESTION 5 ****/
  // start at 1 as assuming input layer has had its outputs set
  for (int output = 1; output < layer->num_outputs; output++) {
    double sum = layer->biases[output];
    for (int input = 0; input < layer->num_inputs; input++) {
      sum += layer->weights[output][input] * layer->prev->outputs[input];
    }
    layer->outputs[output] = sigmoid(sum);
  }
  /* 3 MARKS */
}

/* Computes the delta errors for this layer. */
void layer_compute_deltas(layer_t const *layer) {
  /**** PART 1 - QUESTION 6 ****/
  /* objective: compute layer->deltas */

  /* 2 MARKS */
}

/* Updates weights and biases according to the delta errors given learning rate.
 */
void layer_update(layer_t const *layer, double l_rate) {
  /**** PART 1 - QUESTION 7 ****/
  /* objective: update layer->weights and layer->biases */

  /* 1 MARK */
}
